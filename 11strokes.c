/** Max object to simulate keyboard input  
-- 11oLsen.de
*/


#ifdef WIN_VERSION


#include "ext.h"
#include "ext_obex.h"
#include "windows.h"


// object struct
typedef struct _strokes 
{
	t_object					ob;			
} t_strokes;

// function prototypes
void *strokes_new(t_symbol *s, long argc, t_atom *argv);
void strokes_free(t_strokes *x);
void strokes_assist(t_strokes *x, void *b, long m, long a, char *s);

void strokes_list(t_strokes *x, t_symbol *s, long argc, t_atom *argv);
void strokes_dolist(t_strokes *x, t_symbol *s, long argc, t_atom *argv);
void strokes_do(t_strokes *x, t_symbol *s, long argc, t_atom *argv);

void strokes_pressOrReleaseVK(t_strokes *x, const short k, int press, int forceExtended);
void strokes_pressOrReleaseSC(t_strokes *x, int scancode, int extended, int press);
void strokes_pressOrReleaseChar(t_strokes *x, char c , int press);


// global class pointer variable
void *strokes_class;


void ext_main(void* r)
{	
	t_class *c;
	
	c = class_new("11strokes", (method)strokes_new, (method)strokes_free, 
		(long)sizeof(t_strokes), 0L /* leave NULL!! */, A_GIMME, 0);
	
    class_addmethod(c, (method)strokes_assist,		"assist",	A_CANT, 0);  
	class_addmethod(c, (method)strokes_list,		"list",		A_GIMME, 0);	

	class_register(CLASS_BOX, c); /* CLASS_NOBOX */
	strokes_class = c;
	object_post(NULL, "11strokes 2022/01/30 11OLSEN.DE");
	return 0;
}


void strokes_list(t_strokes *x, t_symbol *s, long argc, t_atom *argv)
{
	defer_low(x, (method)strokes_dolist, s, argc, argv);
}

void strokes_dolist(t_strokes *x, t_symbol *s, long argc, t_atom *argv)	
{
	int i;
	int press;

	// correct args ?
	if (argc != 2 ||  (argv + 0)->a_type != A_LONG || (argv + 1)->a_type != A_LONG)
	{
		object_error((t_object *)x, "wrong input, use list of 2 ints"); 
		return;
	}
	
	press = atom_getlong(argv+1);

	if (press==2)
	{
		atom_setlong(argv+1, 1);
		strokes_do(x, s, argc, argv);
		atom_setlong(argv+1, 0);
		strokes_do(x, s, argc, argv);
		return;
	}
	if (press>2)
	{
		for (i = 0; i<press-1; i++)
		{
			atom_setlong(argv+1, 1);
			strokes_do(x, s, argc, argv);
			atom_setlong(argv+1, 0);
			strokes_do(x, s, argc, argv);
		}
		return;
	}
	if (press == 0 || press == 1)
	{
		strokes_do(x, s, argc, argv);
	}
	else
	{
		object_error((t_object *)x, "wrong input, second int cannot be below 0"); 
		return;
	}
}

void strokes_do(t_strokes *x, t_symbol *s, long argc, t_atom *argv)
{
	int theKey;
	int press;
	int needToToggleNumLock = FALSE;

	theKey = atom_getlong(argv + 0);
	press = atom_getlong(argv + 1);


	if (press && theKey <= 1017 && theKey >= 1000)
	{
		BYTE keyState[256];
		GetKeyboardState((LPBYTE)&keyState);

		if ( !(keyState[VK_NUMLOCK] & 1) )
		{
			needToToggleNumLock = TRUE;
		}
	}



	if (needToToggleNumLock)
	{
		keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
		keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}
	
	
	switch (theKey) 
		{
			case 1:
				strokes_pressOrReleaseVK(x, VK_RETURN, press, 0);
				break;
			case 2: 
				strokes_pressOrReleaseVK(x, VK_TAB, press, 0); 
				break;
			case 3: 
				strokes_pressOrReleaseVK(x, VK_SPACE, press, 0);
				break;
			case 4: 
				strokes_pressOrReleaseVK(x, VK_BACK, press, 0);
				break;
			case 5: 
				strokes_pressOrReleaseVK(x, VK_ESCAPE, press, 0);
				break;
			case 6: 
				strokes_pressOrReleaseVK(x, VK_LCONTROL, press, 0);
				break;
			case 7: 
				strokes_pressOrReleaseVK(x, VK_LSHIFT, press, 0);
				break;
			case 8: 
				strokes_pressOrReleaseVK(x, VK_CAPITAL, press, 0);
				break;
			case 9: 
				strokes_pressOrReleaseVK(x, VK_LMENU, press, 0);
				break;
			case 10: 
				strokes_pressOrReleaseVK(x, VK_LWIN, press, 0);
				break;
			case 11: 
				strokes_pressOrReleaseVK(x, VK_RSHIFT, press, 0);
				break;
			case 12: 
				strokes_pressOrReleaseVK(x, VK_RMENU, press, 0);
				break;
			case 13: 
				strokes_pressOrReleaseVK(x, VK_RWIN, press, 0);
				break;
			case 14: 
				//strokes_pressOrReleaseVK(x, VK_FN?, press, 0);
				break;
			case 15: 
				strokes_pressOrReleaseVK(x, VK_F1, press, 0);
				break;
			case 16: 
				strokes_pressOrReleaseVK(x, VK_F2, press, 0);
				break;
			case 17: 
				strokes_pressOrReleaseVK(x, VK_F3, press, 0);
				break;
			case 18: 
				strokes_pressOrReleaseVK(x, VK_F4, press, 0);
				break;
			case 19: 
				strokes_pressOrReleaseVK(x, VK_F5, press, 0);
				break;
			case 20: 
				strokes_pressOrReleaseVK(x, VK_F6, press, 0);
				break;
			case 21: 
				strokes_pressOrReleaseVK(x, VK_F7, press, 0);
				break;
			case 22: 
				strokes_pressOrReleaseVK(x, VK_F8, press, 0);
				break;
			case 23: 
				strokes_pressOrReleaseVK(x, VK_F9, press, 0);
				break;
			case 24: 
				strokes_pressOrReleaseVK(x, VK_F10, press, 0);
				break;
			case 25: 
				strokes_pressOrReleaseVK(x, VK_F11, press, 0);
				break;
			case 26: 
				strokes_pressOrReleaseVK(x, VK_F12, press, 0);
				break;
			case 27: 
				strokes_pressOrReleaseVK(x, VK_F13, press, 0);
				break;
			case 28: 
				strokes_pressOrReleaseVK(x, VK_F14, press, 0);
				break;
			case 29: 
				strokes_pressOrReleaseVK(x, VK_F15, press, 0);
				break;
			case 30: 
				strokes_pressOrReleaseVK(x, VK_F16, press, 0);
				break;
			case 31: 
				strokes_pressOrReleaseVK(x, VK_F17, press, 0);
				break;
			case 32: 
				strokes_pressOrReleaseVK(x, VK_F18, press, 0);
				break;
			case 33: 
				strokes_pressOrReleaseVK(x, VK_F19, press, 0);
				break;
			case 34: 
				strokes_pressOrReleaseVK(x, VK_F20, press, 0);
				break;
			case 35: 
				strokes_pressOrReleaseVK(x, VK_INSERT, press,1);
				break;
			case 36: 
				strokes_pressOrReleaseVK(x, VK_DELETE, press,1);
				break;
			case 37: 
				strokes_pressOrReleaseVK(x, VK_PRIOR, press,1);
				break;
			case 38: 
				strokes_pressOrReleaseVK(x, VK_NEXT, press,1);
				break;
			case 39: 
				strokes_pressOrReleaseVK(x, VK_HOME, press,1);
				break;
			case 40: 
				strokes_pressOrReleaseVK(x, VK_END, press,1);
				break;
			case 41: 
				strokes_pressOrReleaseVK(x, VK_VOLUME_UP, press, 0);
				break;
			case 42: 
				strokes_pressOrReleaseVK(x, VK_VOLUME_DOWN, press, 0);
				break;
			case 43: 
				strokes_pressOrReleaseVK(x, VK_RIGHT, press, 1);
				break;
			case 44: 
				strokes_pressOrReleaseVK(x, VK_LEFT, press, 1);
				break;
			case 45: 
				strokes_pressOrReleaseVK(x, VK_UP, press, 1);
				break;
			case 46: 
				strokes_pressOrReleaseVK(x, VK_DOWN, press, 1);
				break;

			case 1000: 
				strokes_pressOrReleaseVK(x, VK_NUMPAD0, press, 0);
				break;
			case 1001:
				strokes_pressOrReleaseVK(x, VK_NUMPAD1, press, 0);
				break;
			case 1002:
				strokes_pressOrReleaseVK(x, VK_NUMPAD2, press, 0);
				break;
			case 1003:
				strokes_pressOrReleaseVK(x, VK_NUMPAD3, press, 0);
				break;
			case 1004:
				strokes_pressOrReleaseVK(x, VK_NUMPAD4, press, 0);
				break;
			case 1005:
				strokes_pressOrReleaseVK(x, VK_NUMPAD5, press, 0);
				break;
			case 1006:
				strokes_pressOrReleaseVK(x, VK_NUMPAD6, press, 0);
				break;
			case 1007:
				strokes_pressOrReleaseVK(x, VK_NUMPAD7, press, 0);
				break;
			case 1008:
				strokes_pressOrReleaseVK(x, VK_NUMPAD8, press, 0);
				break;
			case 1009:
				strokes_pressOrReleaseVK(x, VK_NUMPAD9, press, 0);
				break;
			case 1010:
				strokes_pressOrReleaseVK(x, VK_DIVIDE, press, 0);
				break;
			case 1011:
				strokes_pressOrReleaseVK(x, VK_MULTIPLY, press, 0);
				break;
			case 1012:
				strokes_pressOrReleaseVK(x, VK_SUBTRACT, press, 0);
				break;
			case 1013:
				strokes_pressOrReleaseVK(x, VK_ADD, press, 0);
				break;
			case 1014:
				strokes_pressOrReleaseVK(x, VK_RETURN, press, 1);
				break;
			case 1015:
				strokes_pressOrReleaseVK(x, VK_DECIMAL, press, 0);
				break;
			case 1016:
				strokes_pressOrReleaseVK(x, VK_NUMLOCK , press, 0);
				break;
			case 1017:
				// keypad equals mac only
				break;

			case 1018:
				strokes_pressOrReleaseVK(x, VK_PRINT, press, 0);
				break;
			case 1019:
				strokes_pressOrReleaseVK(x, VK_SCROLL, press, 0);
				break;
			case 1020:
				strokes_pressOrReleaseVK(x, VK_PAUSE, press, 0);
				break;
			

			case 47: //a
				strokes_pressOrReleaseVK(x, 0x41, press, 0);
				break;
			case 1047:
				strokes_pressOrReleaseSC(x, (int)0x1E , 0, press);
				break;
			case 48: 
				strokes_pressOrReleaseVK(x, 0x42, press, 0);
				break;
			case 1048:
				strokes_pressOrReleaseSC(x, (int)0x30 , 0, press);
				break;
			case 49: //c
				strokes_pressOrReleaseVK(x, 0x43, press, 0);
				break;
			case 1049:
				strokes_pressOrReleaseSC(x, (int)0x2E , 0, press);
				break;
			case 50: //d
				strokes_pressOrReleaseVK(x, 0x44, press, 0);
				break;
			case 1050:
				strokes_pressOrReleaseSC(x, (int)0x20 , 0, press);
				break;
			case 51://e 
				strokes_pressOrReleaseVK(x, 0x45, press, 0);
				break;
			case 1051:
				strokes_pressOrReleaseSC(x, (int)0x12 , 0, press);
				break;
			case 52: //f
				strokes_pressOrReleaseVK(x, 0x46, press, 0);
				break;
			case 1052:
				strokes_pressOrReleaseSC(x, (int)0x21 , 0, press);
				break;
			case 53: //g
				strokes_pressOrReleaseVK(x, 0x47, press, 0);
				break;
			case 1053:
				strokes_pressOrReleaseSC(x, (int)0x22 , 0, press);
				break;
			case 54: //h
				strokes_pressOrReleaseVK(x, 0x48, press, 0);
				break;
			case 1054:
				strokes_pressOrReleaseSC(x, (int)0x23 , 0, press);
				break;
			case 55: //i
				strokes_pressOrReleaseVK(x, 0x49, press, 0);
				break;
			case 1055:
				strokes_pressOrReleaseSC(x, (int)0x17 , 0, press);
				break;
			case 56: //j
				strokes_pressOrReleaseVK(x, 0x4A, press, 0);
				break;
			case 1056:
				strokes_pressOrReleaseSC(x, (int)0x24 , 0, press);
				break;
			case 57: //k
				strokes_pressOrReleaseVK(x, 0x4B, press, 0);
				break;
			case 1057:
				strokes_pressOrReleaseSC(x, (int)0x25 , 0, press);
				break;
			case 58: //l
				strokes_pressOrReleaseVK(x, 0x4C, press, 0);
				break;
			case 1058:
				strokes_pressOrReleaseSC(x, (int)0x26 , 0, press);
				break;
			case 59: //m
				strokes_pressOrReleaseVK(x, 0x4D, press, 0);
				break;
			case 1059:
				strokes_pressOrReleaseSC(x, (int)0x32 , 0, press);
				break;
			case 60: //n
				strokes_pressOrReleaseVK(x, 0x4E, press, 0);
				break;
			case 1060:
				strokes_pressOrReleaseSC(x, (int)0x31 , 0, press);
				break;
			case 61: //o
				strokes_pressOrReleaseVK(x, 0x4F, press, 0);
				break;
			case 1061:
				strokes_pressOrReleaseSC(x, (int)0x18 , 0, press);
				break;
			case 62: //p
				strokes_pressOrReleaseVK(x, 0x50, press, 0);
				break;
			case 1062:
				strokes_pressOrReleaseSC(x, (int)0x19 , 0, press);
				break;
			case 63: //q
				strokes_pressOrReleaseVK(x, 0x51, press, 0);
				break;
			case 1063:
				strokes_pressOrReleaseSC(x, (int)0x10 , 0, press);
				break;
			case 64: //r
				strokes_pressOrReleaseVK(x, 0x52, press, 0);
				break;
			case 1064:
				strokes_pressOrReleaseSC(x, (int)0x13 , 0, press);
				break;
			case 65: //s
				strokes_pressOrReleaseVK(x, 0x53, press, 0);
				break;
			case 1065:
				strokes_pressOrReleaseSC(x, (int)0x1F , 0, press);
				break;
			case 66: //t
				strokes_pressOrReleaseVK(x, 0x54, press, 0);
				break;
			case 1066:
				strokes_pressOrReleaseSC(x, (int)0x14 , 0, press);
				break;
			case 67: //u
				strokes_pressOrReleaseVK(x, 0x55, press, 0);
				break;
			case 1067:
				strokes_pressOrReleaseSC(x, (int)0x16 , 0, press);
				break;
			case 68: //v
				strokes_pressOrReleaseVK(x, 0x56, press, 0);
				break;
			case 1068:
				strokes_pressOrReleaseSC(x, (int)0x2F , 0, press);
				break;
			case 69: //w
				strokes_pressOrReleaseVK(x, 0x57, press, 0);
				break;
			case 1069:
				strokes_pressOrReleaseSC(x, (int)0x11 , 0, press);
				break;
			case 70: //x
				strokes_pressOrReleaseVK(x, 0x58, press, 0);
				break;
			case 1070:
				strokes_pressOrReleaseSC(x, (int)0x2D , 0, press);
				break;
			case 71: //y
				strokes_pressOrReleaseVK(x, 0x59, press, 0);
				break;
			case 1071:
				strokes_pressOrReleaseSC(x, (int)0x15 , 0, press);
				break;
			case 72: //z
				strokes_pressOrReleaseVK(x, 0x5A, press, 0);
				break;
			case 1072:
				strokes_pressOrReleaseSC(x, (int)0x2C , 0, press);
				break;

			case 73: //0
				strokes_pressOrReleaseChar(x, '0' , press);
				break;
			case 1073:
				strokes_pressOrReleaseSC(x, (int)0x0B , 0, press);
				break;
			case 74: //1
				strokes_pressOrReleaseChar(x, '1' , press);
				break;
			case 1074:
				strokes_pressOrReleaseSC(x, (int)0x02 , 0, press);
				break;
			case 75: //2
				strokes_pressOrReleaseChar(x, '2' , press);
				break;
			case 1075:
				strokes_pressOrReleaseSC(x, (int)0x03 , 0, press);
				break;
			case 76: //3
				strokes_pressOrReleaseChar(x, '3' , press);
				break;
			case 1076:
				strokes_pressOrReleaseSC(x, (int)0x04 , 0, press);
				break;
			case 77: //4
				strokes_pressOrReleaseChar(x, '4' , press);
				break;
			case 1077:
				strokes_pressOrReleaseSC(x, (int)0x05 , 0, press);
				break;
			case 78: //5
				strokes_pressOrReleaseChar(x, '5' , press);
				break;
			case 1078:
				strokes_pressOrReleaseSC(x, (int)0x06 , 0, press);
				break;
			case 79: //6
				strokes_pressOrReleaseChar(x, '6' , press);
				break;
			case 1079:
				strokes_pressOrReleaseSC(x, (int)0x07 , 0, press);
				break;
			case 80: //7
				strokes_pressOrReleaseChar(x, '7' , press);
				break;
			case 1080:
				strokes_pressOrReleaseSC(x, (int)0x08 , 0, press);
				break;
			case 81: //8
				strokes_pressOrReleaseChar(x, '8' , press);
				break;
			case 1081:
				strokes_pressOrReleaseSC(x, (int)0x09 , 0, press);
				break;
			case 82: //9
				strokes_pressOrReleaseChar(x, '9' , press);
				break;
			case 1082:
				strokes_pressOrReleaseSC(x, (int)0x0A , 0, press);
				break;

			case 83: 
				strokes_pressOrReleaseChar(x, '-' , press);
				break;
			case 1083:
				strokes_pressOrReleaseSC(x, (int)0x0C , 0, press);
				break;
			case 84: 
				strokes_pressOrReleaseChar(x, '=' , press);
				break;
			case 1084:
				strokes_pressOrReleaseSC(x, (int)0x0D , 0, press);
				break;
			case 85: 
				strokes_pressOrReleaseChar(x, '[' , press);
				break;
			case 1085:
				strokes_pressOrReleaseSC(x, (int)0x1A , 0, press);
				break;
			case 86: 
				strokes_pressOrReleaseChar(x, ']' , press);
				break;
			case 1086:
				strokes_pressOrReleaseSC(x, (int)0x1B , 0, press);
				break;
			case 87: 
				strokes_pressOrReleaseChar(x, ';' , press);
				break;
			case 1087:
				strokes_pressOrReleaseSC(x, (int)0x27 , 0, press);
				break;
			case 88: 
				strokes_pressOrReleaseChar(x, '\'' , press);
				break;
			case 1088:
				strokes_pressOrReleaseSC(x, (int)0x28 , 0, press);
				break;
			case 89:
				strokes_pressOrReleaseChar(x, '`' , press);
				break;
			case 1089:
				strokes_pressOrReleaseSC(x, (int)0x29 , 0, press);
				break;
			case 90: 
				strokes_pressOrReleaseChar(x, '\\' , press);
				break;
			case 1090:
				strokes_pressOrReleaseSC(x, (int)0x2B , 0, press);
				break;
			case 91: 
				strokes_pressOrReleaseChar(x, ',' , press);
				break;
			case 1091:
				strokes_pressOrReleaseSC(x, (int)0x33 , 0, press);
				break;
			case 92: 
				strokes_pressOrReleaseChar(x, '.' , press);
				break;
			case 1092:
				strokes_pressOrReleaseSC(x, (int)0x34 , 0, press);
				break;
			case 93: 
				strokes_pressOrReleaseChar(x, '/' , press);
				break;
			case 1093:
				strokes_pressOrReleaseSC(x, (int)0x35 , 0, press);
				break;

			case 94: 
				strokes_pressOrReleaseChar(x, '!' , press);
				break;
			case 95: 
				strokes_pressOrReleaseChar(x, '"' , press);
				break;
			case 96: 
				strokes_pressOrReleaseChar(x, '#' , press);
				break;
			case 97: 
				strokes_pressOrReleaseChar(x, '$' , press);
				break;
			case 98: 
				strokes_pressOrReleaseChar(x, '%' , press);
				break;
			case 99: 
				strokes_pressOrReleaseChar(x, '&' , press);
				break;
			case 100: 
				strokes_pressOrReleaseChar(x, '(' , press);
				break;
			case 101: 
				strokes_pressOrReleaseChar(x, ')' , press);
				break;
			case 102: 
				strokes_pressOrReleaseChar(x, '*' , press);
				break;
			case 103: 
				strokes_pressOrReleaseChar(x, '+' , press);
				break;
			case 104: 
				strokes_pressOrReleaseChar(x, ':' , press);
				break;
			case 105: 
				strokes_pressOrReleaseChar(x, '<' , press);
				break;
			case 106: 
				strokes_pressOrReleaseChar(x, '>' , press);
				break;
			case 107: 
				strokes_pressOrReleaseChar(x, '?' , press);
				break;
			case 108: 
				strokes_pressOrReleaseChar(x, '@' , press);
				break;
			case 109: 
				strokes_pressOrReleaseChar(x, '^' , press);
				break;
			case 110: 
				strokes_pressOrReleaseChar(x, '_' , press);
				break;
			case 111: 
				strokes_pressOrReleaseChar(x, '{' , press);
				break;
			case 112: 
				strokes_pressOrReleaseChar(x, '|' , press);
				break;
			case 113: 
				strokes_pressOrReleaseChar(x, '}' , press);
				break;
			case 114: 
				strokes_pressOrReleaseChar(x, '~' , press);
				break;
			case 115: 
				strokes_pressOrReleaseChar(x, '�' , press);
				break;

		}

		if (needToToggleNumLock)
		{
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
}



/// 
/// get the vk and modifiers for the char
///
void strokes_pressOrReleaseChar(t_strokes *x, char c , int press)
{
	bool bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8;
	short vk = VkKeyScanEx( c , GetKeyboardLayout(0) );
	short vkNumber = LOBYTE(vk); 
	short mods = HIBYTE(vk);
	
	if (vkNumber==-1)
	{
		object_error((t_object *)x, "could not find the key(s) for character: %d", c);
		return;
	}

	/*If you want the k-th bit of n, then do
	(n & ( 1 << k )) >> k*/
	
	bit1 = ((mods & ( 1 << 0 )) >> 0 != 0);
	bit2 = ((mods & ( 1 << 1 )) >> 1 != 0);
	bit3 = ((mods & ( 1 << 2 )) >> 2 != 0);
	bit4 = ((mods & ( 1 << 3 )) >> 3 != 0);
	bit5 = ((mods & ( 1 << 4 )) >> 4 != 0);
	bit6 = ((mods & ( 1 << 5 )) >> 5 != 0);
	bit7 = ((mods & ( 1 << 6 )) >> 6 != 0);
	bit8 = ((mods & ( 1 << 7 )) >> 7 != 0);

	
	/*
	object_post((t_object *)x, "vkNumber %d", vkNumber );
	object_post((t_object *)x, "mods %d", mods );
	if (bit1) object_post((t_object *)x, "shift set" );
	if (bit2) object_post((t_object *)x, "ctrl set" );
	if (bit3) object_post((t_object *)x, "alt set" );
	if (bit4) object_post((t_object *)x, "bit4 set" );
	*/
	
	if (bit1) strokes_pressOrReleaseVK(x, VK_SHIFT, 1, 0);
	if (bit2) strokes_pressOrReleaseVK(x, VK_CONTROL, 1, 0);
	if (bit3) strokes_pressOrReleaseVK(x, VK_MENU, 1, 0);

	strokes_pressOrReleaseVK(x, vkNumber, press, 0);

	if (bit3) strokes_pressOrReleaseVK(x, VK_MENU, 0, 0);
	if (bit2) strokes_pressOrReleaseVK(x, VK_CONTROL, 0, 0);
	if (bit1) strokes_pressOrReleaseVK(x, VK_SHIFT, 0, 0);
}



/// 
/// get the scancode for the virtual key code
///
void strokes_pressOrReleaseVK(t_strokes *x, const short k, int press, int forceExtended)
{
	short ex;
	short vsc;
	unsigned int scancode;

	// going back to the scancode because that seems to be more low level
	scancode = MapVirtualKeyEx(k, 4, GetKeyboardLayout(0)); 
	vsc = LOBYTE(scancode);
	if (HIBYTE(scancode)!=0 || forceExtended==1)
		ex = 1; 
	else
		ex = 0;

	strokes_pressOrReleaseSC(x, vsc, ex, press);

}



/// 
/// every keystroke finally ends up here with it's scancode
///
void strokes_pressOrReleaseSC(t_strokes *x, int scancode, int extended, int press)
{
	INPUT inp[1];
	inp[0].type=INPUT_KEYBOARD;

	if (press==1 && extended==1)	{ inp[0].ki.dwFlags=KEYEVENTF_SCANCODE | KEYEVENTF_EXTENDEDKEY; } 
	else if (press==1 )				{ inp[0].ki.dwFlags=KEYEVENTF_SCANCODE; }
	else if (extended==1 )			{ inp[0].ki.dwFlags=KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY; }  
	else							{ inp[0].ki.dwFlags=KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP; }
		
	inp[0].ki.wScan= scancode;
	inp[0].ki.time = 0;

	SendInput(1, inp, sizeof(INPUT));
}




void strokes_assist(t_strokes *x, void *b, long m, long a, char *s)
{
	if (m==1) 
	{ 	// Inlets
		switch (a) 
		{
			case 0: strcpy(s, "list"); break;
			case 1: strcpy(s, ""); break;
		}
	}
}


void strokes_free(t_strokes *x)
{
	;
}



void *strokes_new(t_symbol *s, long argc, t_atom *argv)
{
	t_strokes *x = NULL;
    
    
	if (x = (t_strokes *)object_alloc(strokes_class)) 
	{
       
		;

	}
	return (x);
}



//////////////////////////////////////////// MAC version ///////////////////////////////////////////////////
#else



#include "ext.h"
#include "ext_obex.h"
#import <Carbon/Carbon.h>

////////////////////////// object struct
typedef struct _strokes
{
    t_object	ob;
    int setModifier;

} t_strokes;

///////////////////////// function prototypes

void* strokes_new(t_symbol* s, long argc, t_atom* argv);
void strokes_free(t_strokes* x);
void strokes_assist(t_strokes* x, void* b, long m, long a, char* s);

void strokes_list(t_strokes* x, t_symbol* s, long argc, t_atom* argv);
void strokes_dolist(t_strokes* x, t_symbol* s, long argc, t_atom* argv);
void strokes_do(t_strokes* x, t_symbol* s, long argc, t_atom* argv);
void strokes_pressOrReleaseVK(t_strokes* x, CGKeyCode k, int press);
void strokes_pressOrReleaseChar(t_strokes* x, char c, int press);
char strokes_checkShift(t_strokes* x, CGKeyCode code);
char strokes_checkOption(t_strokes* x, CGKeyCode code);
char strokes_checkNoMods(t_strokes* x, CGKeyCode code);
char strokes_checkShiftOption(t_strokes* x, CGKeyCode code);

CGKeyCode strokes_keyCodeForChar(t_strokes* x, const char c);
CGKeyCode strokes_keyCodeForCharWithLayout(t_strokes* x, const char c, const UCKeyboardLayout* uchrHeader);



// global class pointer variable
void* strokes_class;
//global vars
CGEventFlags strokes_flags;
CGEventSourceRef sourceRef;




void ext_main(void* r)
{
    t_class* c;

    c = class_new("11strokes", (method)strokes_new, (method)strokes_free, (long)sizeof(t_strokes),
        0L /* leave NULL!! */, A_GIMME, 0);

    class_addmethod(c, (method)strokes_list, "list", A_GIMME, 0);


    /* you CAN'T call this from the patcher */
    class_addmethod(c, (method)strokes_assist, "assist", A_CANT, 0);


    class_register(CLASS_BOX, c);
    strokes_class = c;

    sourceRef = CGEventSourceCreate(kCGEventSourceStateCombinedSessionState);

    object_post(NULL, "11strokes 2022/01/30 11OLSEN.DE");
}


void strokes_list(t_strokes* x, t_symbol* s, long argc, t_atom* argv)
{
    defer_low(x, (method)strokes_dolist, s, argc, argv);
}

void strokes_dolist(t_strokes* x, t_symbol* s, long argc, t_atom* argv)
{
    int i;
    int press;

    // correct args ?
    if (argc < 2 || argc > 3 || (argv + 0)->a_type != A_LONG || (argv + 1)->a_type != A_LONG)
    {
        object_error((t_object*)x, "wrong input, use list of 2 ints");
        return;
    }
    if (argc == 3 && (argv + 2)->a_type == A_LONG && atom_getlong(argv + 2) > 0)
    {
        x->setModifier = 1;

    }
    else
    {
        x->setModifier = 0;
    }

    press = atom_getlong(argv + 1);

    if (press == 2)
    {
        atom_setlong(argv + 1, 1);
        strokes_do(x, s, argc, argv);
        atom_setlong(argv + 1, 0);
        strokes_do(x, s, argc, argv);
        return;
    }
    if (press > 2)
    {
        for (i = 0; i < press - 1; i++)
        {
            atom_setlong(argv + 1, 1);
            strokes_do(x, s, argc, argv);
            atom_setlong(argv + 1, 0);
            strokes_do(x, s, argc, argv);
        }
        return;
    }
    if (press == 0 || press == 1)
    {
        strokes_do(x, s, argc, argv);
    }
    else
    {
        object_error((t_object*)x, "wrong input, second int cannot be below 0");
        return;
    }
}


void strokes_do(t_strokes* x, t_symbol* s, long argc, t_atom* argv)
{
    int theKey = atom_getlong(argv + 0);
    int press = atom_getlong(argv + 1);

    switch (theKey)
    {
    case 1:
        strokes_pressOrReleaseVK(x, kVK_Return, press);
        break;
    case 2:
        strokes_pressOrReleaseVK(x, kVK_Tab, press);
        break;
    case 3:
        strokes_pressOrReleaseVK(x, kVK_Space, press);
        break;
    case 4:
        strokes_pressOrReleaseVK(x, kVK_Delete, press);
        break;
    case 5:
        strokes_pressOrReleaseVK(x, kVK_Escape, press);
        break;
    case 6:
        strokes_pressOrReleaseVK(x, kVK_Command, press);
        break;
    case 7:
        strokes_pressOrReleaseVK(x, kVK_Shift, press);
        break;
    case 8:
        strokes_pressOrReleaseVK(x, kVK_CapsLock, press);
        break;
    case 9:
        strokes_pressOrReleaseVK(x, kVK_Option, press);
        break;
    case 10:
        strokes_pressOrReleaseVK(x, kVK_Control, press);
        break;
    case 11:
        strokes_pressOrReleaseVK(x, kVK_RightShift, press);
        break;
    case 12:
        strokes_pressOrReleaseVK(x, kVK_RightOption, press);
        break;
    case 13:
        strokes_pressOrReleaseVK(x, kVK_RightControl, press);
        break;
    case 14:
        strokes_pressOrReleaseVK(x, kVK_Function, press);
        break;
    case 15:
        strokes_pressOrReleaseVK(x, kVK_F1, press);
        break;
    case 16:
        strokes_pressOrReleaseVK(x, kVK_F2, press);
        break;
    case 17:
        strokes_pressOrReleaseVK(x, kVK_F3, press);
        break;
    case 18:
        strokes_pressOrReleaseVK(x, kVK_F4, press);
        break;
    case 19:
        strokes_pressOrReleaseVK(x, kVK_F5, press);
        break;
    case 20:
        strokes_pressOrReleaseVK(x, kVK_F6, press);
        break;
    case 21:
        strokes_pressOrReleaseVK(x, kVK_F7, press);
        break;
    case 22:
        strokes_pressOrReleaseVK(x, kVK_F8, press);
        break;
    case 23:
        strokes_pressOrReleaseVK(x, kVK_F9, press);
        break;
    case 24:
        strokes_pressOrReleaseVK(x, kVK_F10, press);
        break;
    case 25:
        strokes_pressOrReleaseVK(x, kVK_F11, press);
        break;
    case 26:
        strokes_pressOrReleaseVK(x, kVK_F12, press);
        break;
    case 27:
        strokes_pressOrReleaseVK(x, kVK_F13, press);
        break;
    case 28:
        strokes_pressOrReleaseVK(x, kVK_F14, press);
        break;
    case 29:
        strokes_pressOrReleaseVK(x, kVK_F15, press);
        break;
    case 30:
        strokes_pressOrReleaseVK(x, kVK_F16, press);
        break;
    case 31:
        strokes_pressOrReleaseVK(x, kVK_F17, press);
        break;
    case 32:
        strokes_pressOrReleaseVK(x, kVK_F18, press);
        break;
    case 33:
        strokes_pressOrReleaseVK(x, kVK_F19, press);
        break;
    case 34:
        strokes_pressOrReleaseVK(x, kVK_F20, press);
        break;
    case 35:
        strokes_pressOrReleaseVK(x, kVK_Help, press);
        break;
    case 36:
        strokes_pressOrReleaseVK(x, kVK_ForwardDelete, press);
        break;
    case 37:
        strokes_pressOrReleaseVK(x, kVK_PageUp, press);
        break;
    case 38:
        strokes_pressOrReleaseVK(x, kVK_PageDown, press);
        break;
    case 39:
        strokes_pressOrReleaseVK(x, kVK_Home, press);
        break;
    case 40:
        strokes_pressOrReleaseVK(x, kVK_End, press);
        break;
    case 41:
        strokes_pressOrReleaseVK(x, kVK_VolumeUp, press);
        break;
    case 42:
        strokes_pressOrReleaseVK(x, kVK_VolumeDown, press);
        break;
    case 43:
        strokes_pressOrReleaseVK(x, kVK_RightArrow, press);
        break;
    case 44:
        strokes_pressOrReleaseVK(x, kVK_LeftArrow, press);
        break;
    case 45:
        strokes_pressOrReleaseVK(x, kVK_UpArrow, press);
        break;
    case 46:
        strokes_pressOrReleaseVK(x, kVK_DownArrow, press);
        break;

    case 1000:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad0, press);
        break;
    case 1001:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad1, press);
        break;
    case 1002:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad2, press);
        break;
    case 1003:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad3, press);
        break;
    case 1004:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad4, press);
        break;
    case 1005:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad5, press);
        break;
    case 1006:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad6, press);
        break;
    case 1007:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad7, press);
        break;
    case 1008:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad8, press);
        break;
    case 1009:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Keypad9, press);
        break;
    case 1010:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadDivide, press);
        break;
    case 1011:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadMultiply, press);
        break;
    case 1012:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadMinus, press);
        break;
    case 1013:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadPlus, press);
        break;
    case 1014:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadEnter, press);
        break;
    case 1015:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadDecimal, press);
        break;
    case 1016:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadClear, press);
        break;
    case 1017:
        strokes_pressOrReleaseVK(x, kVK_ANSI_KeypadEquals, press);
        break;
    case 1018:
        //strokes_pressOrReleaseVK(x, kVK_, press);
        break;
    case 1019:
        break;
    case 1020:
        break;

    case 47: //a
        strokes_pressOrReleaseChar(x, 'a', press);
        break;
    case 1047:
        strokes_pressOrReleaseVK(x, kVK_ANSI_A, press);
        break;
    case 48: //b
        strokes_pressOrReleaseChar(x, 'b', press);
        break;
    case 1048:
        strokes_pressOrReleaseVK(x, kVK_ANSI_B, press);
        break;
    case 49: //c
        strokes_pressOrReleaseChar(x, 'c', press);
        break;
    case 1049:
        strokes_pressOrReleaseVK(x, kVK_ANSI_C, press);
        break;
    case 50: //d
        strokes_pressOrReleaseChar(x, 'd', press);
        break;
    case 1050:
        strokes_pressOrReleaseVK(x, kVK_ANSI_D, press);
        break;
    case 51://e
        strokes_pressOrReleaseChar(x, 'e', press);
        break;
    case 1051:
        strokes_pressOrReleaseVK(x, kVK_ANSI_E, press);
        break;
    case 52: //f
        strokes_pressOrReleaseChar(x, 'f', press);
        break;
    case 1052:
        strokes_pressOrReleaseVK(x, kVK_ANSI_F, press);
        break;
    case 53: //g
        strokes_pressOrReleaseChar(x, 'g', press);
        break;
    case 1053:
        strokes_pressOrReleaseVK(x, kVK_ANSI_G, press);
        break;
    case 54: //h
        strokes_pressOrReleaseChar(x, 'h', press);
        break;
    case 1054:
        strokes_pressOrReleaseVK(x, kVK_ANSI_H, press);
        break;
    case 55: //i
        strokes_pressOrReleaseChar(x, 'i', press);
        break;
    case 1055:
        strokes_pressOrReleaseVK(x, kVK_ANSI_I, press);
        break;
    case 56: //j
        strokes_pressOrReleaseChar(x, 'j', press);
        break;
    case 1056:
        strokes_pressOrReleaseVK(x, kVK_ANSI_J, press);
        break;
    case 57: //k
        strokes_pressOrReleaseChar(x, 'k', press);
        break;
    case 1057:
        strokes_pressOrReleaseVK(x, kVK_ANSI_K, press);
        break;
    case 58: //l
        strokes_pressOrReleaseChar(x, 'l', press);
        break;
    case 1058:
        strokes_pressOrReleaseVK(x, kVK_ANSI_L, press);
        break;
    case 59: //m
        strokes_pressOrReleaseChar(x, 'm', press);
        break;
    case 1059:
        strokes_pressOrReleaseVK(x, kVK_ANSI_M, press);
        break;
    case 60: //n
        strokes_pressOrReleaseChar(x, 'n', press);
        break;
    case 1060:
        strokes_pressOrReleaseVK(x, kVK_ANSI_N, press);
        break;
    case 61: //o
        strokes_pressOrReleaseChar(x, 'o', press);
        break;
    case 1061:
        strokes_pressOrReleaseVK(x, kVK_ANSI_O, press);
        break;
    case 62: //p
        strokes_pressOrReleaseChar(x, 'p', press);
        break;
    case 1062:
        strokes_pressOrReleaseVK(x, kVK_ANSI_P, press);
        break;
    case 63: //q
        strokes_pressOrReleaseChar(x, 'q', press);
        break;
    case 1063:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Q, press);
        break;
    case 64: //r
        strokes_pressOrReleaseChar(x, 'r', press);
        break;
    case 1064:
        strokes_pressOrReleaseVK(x, kVK_ANSI_R, press);
        break;
    case 65: //s
        strokes_pressOrReleaseChar(x, 's', press);
        break;
    case 1065:
        strokes_pressOrReleaseVK(x, kVK_ANSI_S, press);
        break;
    case 66: //t
        strokes_pressOrReleaseChar(x, 't', press);
        break;
    case 1066:
        strokes_pressOrReleaseVK(x, kVK_ANSI_T, press);
        break;
    case 67: //u
        strokes_pressOrReleaseChar(x, 'u', press);
        break;
    case 1067:
        strokes_pressOrReleaseVK(x, kVK_ANSI_U, press);
        break;
    case 68: //v
        strokes_pressOrReleaseChar(x, 'v', press);
        break;
    case 1068:
        strokes_pressOrReleaseVK(x, kVK_ANSI_V, press);
        break;
    case 69: //w
        strokes_pressOrReleaseChar(x, 'w', press);
        break;
    case 1069:
        strokes_pressOrReleaseVK(x, kVK_ANSI_W, press);
        break;
    case 70: //x
        strokes_pressOrReleaseChar(x, 'x', press);
        break;
    case 1070:
        strokes_pressOrReleaseVK(x, kVK_ANSI_X, press);
        break;
    case 71: //y
        strokes_pressOrReleaseChar(x, 'y', press);
        break;
    case 1071:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Y, press);
        break;
    case 72: //z
        strokes_pressOrReleaseChar(x, 'z', press);
        break;
    case 1072:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Z, press);
        break;

    case 73: //0
        strokes_pressOrReleaseChar(x, '0', press);
        break;
    case 1073:
        strokes_pressOrReleaseVK(x, kVK_ANSI_0, press);
        break;
    case 74: //1
        strokes_pressOrReleaseChar(x, '1', press);
        break;
    case 1074:
        strokes_pressOrReleaseVK(x, kVK_ANSI_1, press);
        break;
    case 75: //2
        strokes_pressOrReleaseChar(x, '2', press);
        break;
    case 1075:
        strokes_pressOrReleaseVK(x, kVK_ANSI_2, press);
        break;
    case 76: //3
        strokes_pressOrReleaseChar(x, '3', press);
        break;
    case 1076:
        strokes_pressOrReleaseVK(x, kVK_ANSI_3, press);
        break;
    case 77: //4
        strokes_pressOrReleaseChar(x, '4', press);
        break;
    case 1077:
        strokes_pressOrReleaseVK(x, kVK_ANSI_4, press);
        break;
    case 78: //5
        strokes_pressOrReleaseChar(x, '5', press);
        break;
    case 1078:
        strokes_pressOrReleaseVK(x, kVK_ANSI_5, press);
        break;
    case 79: //6
        strokes_pressOrReleaseChar(x, '6', press);
        break;
    case 1079:
        strokes_pressOrReleaseVK(x, kVK_ANSI_6, press);
        break;
    case 80: //7
        strokes_pressOrReleaseChar(x, '7', press);
        break;
    case 1080:
        strokes_pressOrReleaseVK(x, kVK_ANSI_7, press);
        break;
    case 81: //8
        strokes_pressOrReleaseChar(x, '8', press);
        break;
    case 1081:
        strokes_pressOrReleaseVK(x, kVK_ANSI_8, press);
        break;
    case 82: //9
        strokes_pressOrReleaseChar(x, '9', press);
        break;
    case 1082:
        strokes_pressOrReleaseVK(x, kVK_ANSI_9, press);
        break;

    case 83:
        strokes_pressOrReleaseChar(x, '-', press);
        break;
    case 1083:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Minus, press);
        break;
    case 84:
        strokes_pressOrReleaseChar(x, '=', press);
        break;
    case 1084:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Equal, press);
        break;
    case 85:
        strokes_pressOrReleaseChar(x, '[', press);
        break;
    case 1085:
        strokes_pressOrReleaseVK(x, kVK_ANSI_LeftBracket, press);
        break;
    case 86:
        strokes_pressOrReleaseChar(x, ']', press);
        break;
    case 1086:
        strokes_pressOrReleaseVK(x, kVK_ANSI_RightBracket, press);
        break;
    case 87:
        strokes_pressOrReleaseChar(x, ';', press);
        break;
    case 1087:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Semicolon, press);
        break;
    case 88:
        strokes_pressOrReleaseChar(x, '\'', press);
        break;
    case 1088:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Quote, press);
        break;
    case 89:
        strokes_pressOrReleaseChar(x, '`', press);
        break;
    case 1089:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Grave, press);
        break;
    case 90:
        strokes_pressOrReleaseChar(x, '\\', press);
        break;
    case 1090:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Backslash, press);
        break;
    case 91:
        strokes_pressOrReleaseChar(x, ',', press);
        break;
    case 1091:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Comma, press);
        break;
    case 92:
        strokes_pressOrReleaseChar(x, '.', press);
        break;
    case 1092:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Period, press);
        break;
    case 93:
        strokes_pressOrReleaseChar(x, '/', press);
        break;
    case 1093:
        strokes_pressOrReleaseVK(x, kVK_ANSI_Slash, press);
        break;

    case 94:
        strokes_pressOrReleaseChar(x, '!', press);
        break;
    case 95:
        strokes_pressOrReleaseChar(x, '"', press);
        break;
    case 96:
        strokes_pressOrReleaseChar(x, '#', press);
        break;
    case 97:
        strokes_pressOrReleaseChar(x, '$', press);
        break;
    case 98:
        strokes_pressOrReleaseChar(x, '%', press);
        break;
    case 99:
        strokes_pressOrReleaseChar(x, '&', press);
        break;
    case 100:
        strokes_pressOrReleaseChar(x, '(', press);
        break;
    case 101:
        strokes_pressOrReleaseChar(x, ')', press);
        break;
    case 102:
        strokes_pressOrReleaseChar(x, '*', press);
        break;
    case 103:
        strokes_pressOrReleaseChar(x, '+', press);
        break;
    case 104:
        strokes_pressOrReleaseChar(x, ':', press);
        break;
    case 105:
        strokes_pressOrReleaseChar(x, '<', press);
        break;
    case 106:
        strokes_pressOrReleaseChar(x, '>', press);
        break;
    case 107:
        strokes_pressOrReleaseChar(x, '?', press);
        break;
    case 108:
        strokes_pressOrReleaseChar(x, '@', press);
        break;
    case 109:
        strokes_pressOrReleaseChar(x, '^', press);
        break;
    case 110:
        strokes_pressOrReleaseChar(x, '_', press);
        break;
    case 111:
        strokes_pressOrReleaseChar(x, '{', press);
        break;
    case 112:
        strokes_pressOrReleaseChar(x, '|', press);
        break;
    case 113:
        strokes_pressOrReleaseChar(x, '}', press);
        break;
    case 114:
        strokes_pressOrReleaseChar(x, '~', press);
        break;



    }

}



void strokes_pressOrReleaseVK(t_strokes* x, CGKeyCode k, int press)
{
    CGEventFlags tempflags;

    if (press == 1)
    {

        //  -------------------------------- set modifier mask
        if (k == 55)
        {
            tempflags = kCGEventFlagMaskCommand;
            strokes_flags = tempflags | strokes_flags;
        }
        else if (k == 56 || k == 60)
        {
            tempflags = kCGEventFlagMaskShift;
            strokes_flags = tempflags | strokes_flags;
        }
        else if (k == 57)
        {
            tempflags = kCGEventFlagMaskAlphaShift;
            strokes_flags = tempflags | strokes_flags;
        }
        else if (k == 58 || k == 61)
        {
            tempflags = kCGEventFlagMaskAlternate;
            strokes_flags = tempflags | strokes_flags;
        }
        else if (k == 59 || k == 62)
        {
            tempflags = kCGEventFlagMaskControl;
            strokes_flags = tempflags | strokes_flags;
        }
        else if (k == 63)
        {
            tempflags = kCGEventFlagMaskSecondaryFn;
            strokes_flags = tempflags | strokes_flags;
        }

        if (x->setModifier < 1)
        {
            CGEventRef e = CGEventCreateKeyboardEvent(sourceRef, (CGKeyCode)k, 1);
            CGEventSetFlags(e, strokes_flags); //
            CGEventPost(kCGHIDEventTap, e);
            CFRelease(e);//
        }


    }
    else if (press == 0)
    {
        //      -------------------------------- filter key-up

        //      -------------------------------- set modifier mask
        if (k == 55) {
            tempflags = kCGEventFlagMaskCommand;
            strokes_flags = ~(tempflags)&strokes_flags;
        }
        else if (k == 56 || k == 60) {
            tempflags = kCGEventFlagMaskShift;
            strokes_flags = ~(tempflags)&strokes_flags;
        }
        else if (k == 57) {
            tempflags = kCGEventFlagMaskAlphaShift;
            strokes_flags = ~(tempflags)&strokes_flags;
        }
        else if (k == 58 || k == 61) {
            tempflags = kCGEventFlagMaskAlternate;
            strokes_flags = ~(tempflags)&strokes_flags;
        }
        else if (k == 59 || k == 62) {
            tempflags = kCGEventFlagMaskControl;
            strokes_flags = ~(tempflags)&strokes_flags;
        }
        else if (k == 63) {
            tempflags = kCGEventFlagMaskSecondaryFn;
            strokes_flags = ~(tempflags)&strokes_flags;
        }

        if (x->setModifier < 1)
        {
            CGEventRef e = CGEventCreateKeyboardEvent(sourceRef, (CGKeyCode)k, 0);
            CGEventSetFlags(e, strokes_flags); //
            CGEventPost(kCGHIDEventTap, e);
            CFRelease(e);//
        }
    }
}

void strokes_pressOrReleaseChar(t_strokes* x, char c, int press)
{
    CGEventFlags tempflags;
    int mods = 0;
    CGKeyCode code = strokes_keyCodeForChar(x, c);
    //object_post((t_object *)x, "------------ find key(s) ------------" );
    //object_post((t_object *)x, "input char: %u", c );
    //object_post((t_object *)x, "kVKcode: %u", code );

    if (strokes_checkNoMods(x, code) == c)
    {
        mods = 0;
        //object_post((t_object *)x, "no mods needed");
        ;
    }

    else if (strokes_checkShift(x, code) == c)
    {
        mods = 1;
        //object_post((t_object *)x, "shift state needed");
        tempflags = kCGEventFlagMaskShift;
        strokes_flags = tempflags | strokes_flags;
    }
    else if (strokes_checkOption(x, code) == c)
    {
        mods = 2;
        //object_post((t_object *)x, "option state needed");
        tempflags = kCGEventFlagMaskAlternate;
        strokes_flags = tempflags | strokes_flags;
    }
    else if (strokes_checkShiftOption(x, code) == c)
    {
        mods = 3;
        //object_post((t_object *)x, "shift+option state needed");
        tempflags = kCGEventFlagMaskShift;
        strokes_flags = tempflags | strokes_flags;
        tempflags = kCGEventFlagMaskAlternate;
        strokes_flags = tempflags | strokes_flags;
    }

    strokes_pressOrReleaseVK(x, code, press);

    if (mods == 1)
    {
        tempflags = kCGEventFlagMaskShift;
        strokes_flags = ~(tempflags)&strokes_flags;
    }
    else if (mods == 2)
    {
        tempflags = kCGEventFlagMaskAlternate;
        strokes_flags = ~(tempflags)&strokes_flags;
    }
    else if (mods == 3)
    {
        tempflags = kCGEventFlagMaskShift;
        strokes_flags = ~(tempflags)&strokes_flags;
        tempflags = kCGEventFlagMaskAlternate;
        strokes_flags = ~(tempflags)&strokes_flags;
    }

}

//(define-event-modifier-flag modifier-active-flag       (<< 1  0))
//(define-event-modifier-flag modifier-btn-state         (<< 1  7))
//(define-event-modifier-flag modifier-cmd-key           (<< 1  8))
//(define-event-modifier-flag modifier-shift-key         (<< 1  9))
//(define-event-modifier-flag modifier-alpha-lock        (<< 1 10))
//(define-event-modifier-flag modifier-option-key        (<< 1 11))
//(define-event-modifier-flag modifier-control-key       (<< 1 12))

//you want to use the Carbon-era shiftKey bit mask shifted right 8 bits (as shown in the documentation for UCKeyTranslate()). shiftKey is 1 << 9, so shiftKey >> 8 is 1 << 1.


char strokes_checkNoMods(t_strokes* x, CGKeyCode code)
{

    TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();
    CFDataRef layoutData = TISGetInputSourceProperty(currentKeyboard, kTISPropertyUnicodeKeyLayoutData);

    const UCKeyboardLayout* keyboardLayout = (const UCKeyboardLayout*)CFDataGetBytePtr(layoutData);
    UInt16 keycode = code; //kVK_ANSI_Period;
    UInt16 keyaction = kUCKeyActionDisplay;
    UInt32 modifierKeyState = 0;                         // Shift
    //UInt32 keyboardType        = LMGetKbdType();
    OptionBits keyTranslateOptions = kUCKeyTranslateNoDeadKeysBit;
    UInt32 deadKeyState = 0;                                      // Is 0 the correct value?
    UInt32 maxStringLength = 4;                                // uint32
    UniChar chars[4]; //   = [0,0,0,0]
    UniCharCount actualStringLength = 1;
    OSStatus  result = UCKeyTranslate(keyboardLayout, keycode, keyaction, modifierKeyState, LMGetKbdType(), keyTranslateOptions, &deadKeyState, maxStringLength, &actualStringLength, chars);
    CFRelease(currentKeyboard);
    //object_post((t_object *)x, "NoMods char: %u", chars[0] );
    return chars[0];
}
char strokes_checkShift(t_strokes* x, CGKeyCode code)
{

    TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();
    CFDataRef layoutData = TISGetInputSourceProperty(currentKeyboard, kTISPropertyUnicodeKeyLayoutData);

    const UCKeyboardLayout* keyboardLayout = (const UCKeyboardLayout*)CFDataGetBytePtr(layoutData);
    UInt16 keycode = code; //kVK_ANSI_Period;
    UInt16 keyaction = kUCKeyActionDisplay;
    UInt32 modifierKeyState = 1 << 1;                         // Shift
    //UInt32 keyboardType        = LMGetKbdType();
    OptionBits keyTranslateOptions = kUCKeyTranslateNoDeadKeysBit;
    UInt32 deadKeyState = 0;                                      // Is 0 the correct value?
    UInt32 maxStringLength = 4;                                // uint32
    UniChar chars[4]; //   = [0,0,0,0]
    UniCharCount actualStringLength = 1;
    OSStatus  result = UCKeyTranslate(keyboardLayout, keycode, keyaction, modifierKeyState, LMGetKbdType(), keyTranslateOptions, &deadKeyState, maxStringLength, &actualStringLength, chars);
    CFRelease(currentKeyboard);
    //object_post((t_object *)x, "Shift char: %u", chars[0] );
    return chars[0];
}
char strokes_checkOption(t_strokes* x, CGKeyCode code)
{

    TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();
    CFDataRef layoutData = TISGetInputSourceProperty(currentKeyboard, kTISPropertyUnicodeKeyLayoutData);

    const UCKeyboardLayout* keyboardLayout = (const UCKeyboardLayout*)CFDataGetBytePtr(layoutData);
    UInt16 keycode = code; //kVK_ANSI_Period;                         // Keycode for a
    UInt16 keyaction = kUCKeyActionDisplay;
    UInt32 modifierKeyState = 1 << 3;                         // Option
    //UInt32 keyboardType        = LMGetKbdType();
    OptionBits keyTranslateOptions = kUCKeyTranslateNoDeadKeysBit;
    UInt32 deadKeyState = 0;                                      // Is 0 the correct value?
    UInt32 maxStringLength = 4;                                // uint32
    UniChar chars[4]; //   = [0,0,0,0]
    UniCharCount actualStringLength = 1;
    OSStatus  result = UCKeyTranslate(keyboardLayout, keycode, keyaction, modifierKeyState, LMGetKbdType(), keyTranslateOptions, &deadKeyState, maxStringLength, &actualStringLength, chars);
    CFRelease(currentKeyboard);
    //object_post((t_object *)x, "Option char: %u", chars[0] );
    return chars[0];
}
char strokes_checkShiftOption(t_strokes* x, CGKeyCode code)
{

    TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();
    CFDataRef layoutData = TISGetInputSourceProperty(currentKeyboard, kTISPropertyUnicodeKeyLayoutData);

    const UCKeyboardLayout* keyboardLayout = (const UCKeyboardLayout*)CFDataGetBytePtr(layoutData);
    UInt16 keycode = code;
    UInt16 keyaction = kUCKeyActionDisplay;
    UInt32 shift = 1 << 1;
    UInt32 option = 1 << 3;
    UInt32 modifierKeyState = shift | option;                         // Option
    //UInt32 keyboardType        = LMGetKbdType();
    OptionBits keyTranslateOptions = kUCKeyTranslateNoDeadKeysBit;
    UInt32 deadKeyState = 0;                                      // Is 0 the correct value?
    UInt32 maxStringLength = 4;                                // uint32
    UniChar chars[4]; //   = [0,0,0,0]
    UniCharCount actualStringLength = 1;
    OSStatus  result = UCKeyTranslate(keyboardLayout, keycode, keyaction, modifierKeyState, LMGetKbdType(), keyTranslateOptions, &deadKeyState, maxStringLength, &actualStringLength, chars);
    CFRelease(currentKeyboard);
    //object_post((t_object *)x, "Shift+Option char: %u", chars[0] );
    return chars[0];
}






CGKeyCode strokes_keyCodeForChar(t_strokes* x, const char c)
{
    CFDataRef currentLayoutData;
    TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();

    if (currentKeyboard == NULL) {
        object_error((t_object*)x, "Could not find keyboard layout\n");
        return UINT16_MAX;
    }

    currentLayoutData = TISGetInputSourceProperty(currentKeyboard,
        kTISPropertyUnicodeKeyLayoutData);
    CFRelease(currentKeyboard);
    if (currentLayoutData == NULL) {
        object_error((t_object*)x, "Could not find layout data\n");
        return UINT16_MAX;
    }

    return strokes_keyCodeForCharWithLayout(x, c, (const UCKeyboardLayout*)CFDataGetBytePtr(currentLayoutData));
}



//
// found this method somewhere on the web
//
CGKeyCode strokes_keyCodeForCharWithLayout(t_strokes* x, const char c, const UCKeyboardLayout* uchrHeader)
{
    //UCKeyboardTypeHeader *uchrKeyboardList;
    uint8_t* uchrData = (uint8_t*)uchrHeader;
    UCKeyboardTypeHeader* uchrKeyboardList = uchrHeader->keyboardTypeList;
    ItemCount i, j;

    /* Loop through the keyboard type list. */
    for (i = 0; i < uchrHeader->keyboardTypeCount; ++i)
    {
        /* Get a pointer to the keyToCharTable structure. */
        UCKeyToCharTableIndex* uchrKeyIX = (UCKeyToCharTableIndex*)(uchrData + (uchrKeyboardList[i].keyToCharTableIndexOffset));
        UCKeyStateRecordsIndex* stateRecordsIndex;

        /* Not sure what this is for but it appears to be a safeguard... */
        if (uchrKeyboardList[i].keyStateRecordsIndexOffset != 0)
        {
            stateRecordsIndex = (UCKeyStateRecordsIndex*)(uchrData + (uchrKeyboardList[i].keyStateRecordsIndexOffset));

            if ((stateRecordsIndex->keyStateRecordsIndexFormat) != kUCKeyStateRecordsIndexFormat)
            {
                stateRecordsIndex = NULL;
            }

        }
        else
        {
            stateRecordsIndex = NULL;
        }

        /* Make sure structure is a table that can be searched. */
        if ((uchrKeyIX->keyToCharTableIndexFormat) != kUCKeyToCharTableIndexFormat)
        {
            continue;
        }

        /* Check the table of each keyboard for character */
        for (j = 0; j < uchrKeyIX->keyToCharTableCount; ++j) {
            UCKeyOutput* keyToCharData = (UCKeyOutput*)(uchrData + (uchrKeyIX->keyToCharTableOffsets[j]));

            /* Check THIS table of the keyboard for the character. */
            UInt16 k;
            for (k = 0; k < uchrKeyIX->keyToCharTableSize; ++k) {
                /* Here's the strange safeguard again... */
                if ((keyToCharData[k] & kUCKeyOutputTestForIndexMask) == kUCKeyOutputStateIndexMask)
                {

                    long keyIndex = (keyToCharData[k] & kUCKeyOutputGetIndexMask);

                    if (stateRecordsIndex != NULL && keyIndex <= (stateRecordsIndex->keyStateRecordCount))
                    {
                        UCKeyStateRecord* stateRecord = (UCKeyStateRecord*)(uchrData + (stateRecordsIndex->keyStateRecordOffsets[keyIndex]));

                        if ((stateRecord->stateZeroCharData) == c)
                        {
                            return (CGKeyCode)k;
                        }
                    }
                    else if (keyToCharData[k] == c)
                    {
                        return (CGKeyCode)k;
                    }
                }
                else if (((keyToCharData[k] & kUCKeyOutputTestForIndexMask) != kUCKeyOutputSequenceIndexMask) && keyToCharData[k] != 0xFFFE && keyToCharData[k] != 0xFFFF && keyToCharData[k] == c)
                {
                    return (CGKeyCode)k;
                }
            }
        }
    }

    return UINT16_MAX;
}



void strokes_assist(t_strokes* x, void* b, long m, long a, char* s)
{
    if (m == 1)
    {     // Inlets
        switch (a)
        {
        case 0: strcpy(s, "list"); break;
        case 1: strcpy(s, ""); break;
        }
    }
}

void strokes_free(t_strokes* x)
{
    ;
}

void* strokes_new(t_symbol* s, long argc, t_atom* argv)
{
    t_strokes* x = NULL;

    if ((x = (t_strokes*)object_alloc(strokes_class)))
    {
        ;

    }
    x->setModifier = 0;
    return (x);
}






#endif