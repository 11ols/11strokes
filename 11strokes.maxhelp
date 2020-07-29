{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 1,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 195.0, 152.0, 1068.0, 790.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 10.0,
		"default_fontface" : 1,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "11patcher-1",
		"subpatcher_template" : "11oLsen",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 36.75, 406.0, 29.5, 20.0 ],
					"text" : "0 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-53",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 36.75, 377.0, 71.0, 20.0 ],
					"text" : "pipe 0 0 2500"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 96.5, 310.0, 146.0, 18.0 ],
					"text" : "press RightArrow 10 times"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 56.0, 310.0, 33.0, 20.0 ],
					"text" : "43 11"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 132.0, 280.0, 107.0, 18.0 ],
					"text" : "types letter \"A\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 56.0, 280.0, 67.0, 20.0 ],
					"presentation_linecount" : 4,
					"text" : "7 1, 47 2, 7 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 56.0, 249.0, 29.5, 20.0 ],
					"text" : "47 2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 92.5, 249.0, 146.0, 18.0 ],
					"text" : "types letter \"a\""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.760784, 0.878431, 0.796078, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-36",
					"linecount" : 18,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 797.0, 423.800048999999944, 52.0, 255.0 ],
					"presentation_linecount" : 18,
					"text" : "1000\n1001\n1002\n1003\n1004\n1005\n1006\n1007\n1008\n1009\n1010\n1011\n1012\n1013\n1014\n1015\n1016\n1017",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 39.916666666666657, 646.0, 50.0, 20.0 ],
					"text" : "31"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 39.916666666666657, 606.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 156.416666666666657, 716.0, 50.0, 20.0 ],
					"text" : "-10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 117.583333333333343, 692.0, 50.0, 20.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 78.75, 670.0, 50.0, 20.0 ],
					"text" : "125"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 70.916666666666657, 606.0, 135.5, 20.0 ],
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 0.964706, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-26",
					"linecount" : 18,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 853.0, 423.800048999999944, 169.25, 255.0 ],
					"text" : "Keypad 0\nKeypad 1\nKeypad 2\nKeypad 3        \nKeypad 4\nKeypad 5\nKeypad 6\nKeypad 7\nKeypad 8\nKeypad 9    \nKeypad Divide\nKeypad Multiply\nKeypad Subtract\nKeypad Add\nKeypad Enter\nKeypad Decimal\nKeypad Clear (NumLock)\nKeypad Equals (Mac only!)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 72.5, 406.0, 52.5, 29.0 ],
					"text" : "delay for testing "
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Lucida Console",
					"id" : "obj-37",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 14.0, 10.0, 262.0, 56.0 ],
					"text" : "[11strokes] (2020)\n- creates global keyboard events\n- cross-platform and to a certain degree \n  independent from users keyboard layout\n- by 11OLSEN.DE",
					"textcolor" : [ 0.019608, 0.254902, 0.035294, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "textedit",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 84.75, 514.300048999999944, 121.666666666666629, 65.0 ],
					"text" : "aAAAAAAAAA"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-31",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 62.0, 128.0, 166.0, 82.0 ],
					"text" : "second value: \n1 for key down, 0 for key up\n2 for key down + up\n3 for 2 x key down and up  \n4 for 3 x key down and up\n...  ",
					"textcolor" : [ 0.513726, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 11.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 62.0, 107.900002000000001, 166.0, 19.0 ],
					"text" : "first value: code for the key",
					"textcolor" : [ 0.047059, 0.513726, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-33",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 62.0, 85.0, 129.0, 20.0 ],
					"text" : "send a list of 2 ints:"
				}

			}
, 			{
				"box" : 				{
					"angle" : 0.0,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"id" : "obj-34",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 54.5, 80.0, 179.5, 134.0 ],
					"proportion" : 0.39
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.760784, 0.878431, 0.796078, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-16",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 529.0, 21.0, 246.0, 62.0 ],
					"text" : "green numbers address a specific key position on the hardware, the key may create a totally different char if it is not the US default layout  "
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.8, 0.964706, 0.984314, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-14",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 787.0, 21.0, 246.0, 62.0 ],
					"text" : "blue numbers address the correct key or key combination that creates the character, depending on the keyboard layout "
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.8, 0.964706, 0.984314, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-23",
					"linecount" : 21,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 817.0, 108.5, 32.0, 296.0 ],
					"text" : "94\n95\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n114",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 0.964706, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-27",
					"linecount" : 21,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 853.0, 108.5, 169.25, 296.0 ],
					"text" : "! Exclamation mark\n\" Double quotes \n# Number\n$ Dollar\n% Procenttecken\n& Ampersand\n( Open parenthesis\n) Close parenthesis \n* Asterisk\n+ Plus\n: Colon\n< Less than \n> Greater than \n? Question mark\n@ At symbol\n^ Caret - circumflex\n_ Underscore\n{ Opening brace\n| Vertical bar\n} Closing brace\n~ Equivalency sign, tilde"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-20",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 301.0, 22.0, 203.0, 34.0 ],
					"text" : "these should be the same with any keyboard layout"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.760784, 0.878431, 0.796078, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-18",
					"linecount" : 47,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 529.0, 95.0, 52.0, 655.0 ],
					"text" : "1047\n1048\n1049\n1050\n1051\n1052\n1053\n1054\n1055\n1056\n1057\n1058\n1059\n1060\n1061\n1062\n1063\n1064\n1065\n1066\n1067\n1068\n1069\n1070\n1071\n1072\n1073\n1074\n1075\n1076\n1077\n1078\n1079\n1080\n1081\n1082\n1083\n1084\n1085\n1086\n1087\n1088\n1089\n1090\n1091\n1092\n1093",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.8, 0.964706, 0.984314, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-7",
					"linecount" : 47,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 585.0, 95.0, 32.0, 655.0 ],
					"text" : "47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60\n61\n62\n63\n64\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n81\n82\n83\n84\n85\n86\n87\n88\n89\n90\n91\n92\n93",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 0.964706, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-9",
					"linecount" : 47,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 621.0, 95.0, 148.0, 655.0 ],
					"text" : "a\nb  \nc\nd \ne\nf\ng\nh\ni\nj\nk\nl\nm\nn\no\np\nq\nr\ns\nt\nu\nv\nw\nx\ny\nz\n0\n1\n2\n3            \n4\n5    \n6\n7\n8\n9\n- Hyphen\n= Equals\n[ Opening bracket\n] Closing bracket\n; Semicolon\n' Single quote\n` Grave accent\n\\ Backslash\n, Comma\n. Period, dot or full stop\n/ Slash or divide"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-1",
					"linecount" : 46,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 301.0, 66.0, 43.0, 641.0 ],
					"text" : "1 \n2 \n3 \n4 \n5\n6 \n7 \n8 \n9 \n10\n11 \n12\n13 \n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46 ",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 0.964706, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"id" : "obj-80",
					"linecount" : 46,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 348.0, 66.0, 158.0, 641.0 ],
					"text" : "Return\nTab\nSpace\nDelete (Backspace)          \nEscape\nCommand (Ctrl)\nShift\nCapsLock\nOption (Alt)\nControl (Win Key)        \nRightShift\nRightOption (Alt) \nRightControl (Win Key) \nFunction Key (Mac only!)\nF1\nF2\nF3\nF4\nF5\nF6\nF7\nF8\nF9\nF10\nF11\nF12\nF13\nF14\nF15\nF16\nF17\nF18\nF19\nF20\nHelp (Insert)\nForwardDelete (Delete)\nPageUp\nPageDown\nHome\nEnd\nVolumeUp\nVolumeDown\nRightArrow\nLeftArrow\nUpArrow\nDownArrow"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.819608, 0.054902, 0.054902, 1.0 ],
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 36.75, 463.5, 55.0, 20.0 ],
					"text" : "11strokes"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"order" : 0,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"order" : 1,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 1 ],
					"source" : [ "obj-22", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 1 ],
					"source" : [ "obj-22", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 1 ],
					"source" : [ "obj-22", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"midpoints" : [ 65.5, 272.0, 46.25, 272.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"midpoints" : [ 65.5, 306.5, 46.25, 306.5 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"midpoints" : [ 65.5, 334.5, 46.25, 334.5 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-54", 1 ],
					"source" : [ "obj-53", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-54", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"midpoints" : [ 46.25, 450.0, 46.25, 450.0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "11strokes.mxe64",
				"type" : "mx64"
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "11patcher",
				"default" : 				{
					"patchlinecolor" : [ 0.32549, 0.345098, 0.372549, 0.94 ],
					"bgfillcolor" : 					{
						"type" : "gradient",
						"color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"color1" : [ 0.65098, 0.666667, 0.662745, 1.0 ],
						"color2" : [ 0.4478, 0.484701, 0.47346, 1.0 ],
						"angle" : 270.0,
						"proportion" : 0.39,
						"autogradient" : 0
					}
,
					"accentcolor" : [ 0.589653, 0.589635, 0.589645, 1.0 ],
					"bgcolor" : [ 0.862745, 0.870588, 0.878431, 1.0 ],
					"textcolor_inverse" : [ 0.0, 0.0, 0.0, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "11patcher-1",
				"default" : 				{
					"patchlinecolor" : [ 0.32549, 0.345098, 0.372549, 0.94 ],
					"fontsize" : [ 10.0 ],
					"bgfillcolor" : 					{
						"type" : "gradient",
						"color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"color1" : [ 0.65098, 0.666667, 0.662745, 1.0 ],
						"color2" : [ 0.4478, 0.484701, 0.47346, 1.0 ],
						"angle" : 270.0,
						"proportion" : 0.39,
						"autogradient" : 0
					}
,
					"accentcolor" : [ 0.589653, 0.589635, 0.589645, 1.0 ],
					"color" : [ 0.113725, 0.580392, 0.737255, 1.0 ],
					"bgcolor" : [ 0.984314, 0.976471, 0.976471, 1.0 ],
					"fontface" : [ 1 ],
					"textcolor_inverse" : [ 0.0, 0.0, 0.0, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ],
		"default_bgcolor" : [ 0.984314, 0.976471, 0.976471, 1.0 ],
		"color" : [ 0.113725, 0.580392, 0.737255, 1.0 ],
		"accentcolor" : [ 0.589653, 0.589635, 0.589645, 1.0 ],
		"textcolor_inverse" : [ 0.0, 0.0, 0.0, 1.0 ],
		"patchlinecolor" : [ 0.32549, 0.345098, 0.372549, 0.94 ],
		"bgfillcolor_type" : "gradient",
		"bgfillcolor_color1" : [ 0.65098, 0.666667, 0.662745, 1.0 ],
		"bgfillcolor_color2" : [ 0.4478, 0.484701, 0.47346, 1.0 ],
		"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ]
	}

}
