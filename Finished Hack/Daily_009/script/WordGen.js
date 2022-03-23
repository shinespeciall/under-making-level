/***Changelog:
 * this patch is used when you want to put letter Tile16 into Layer 0
 * make sure you insert letter Tile16 into the current Tileset first
 * P.S. modify some constants then use it, don't use it directly
 *                  ssp (shinespeciall) released the script at 03/13/2022
 **/

var base_offset = 0x0C8; // at "0"
var letter_map = ["0", "1", "2", "3", "4", "5", "6", "7", 
				  "8", "9", "A", "B", "C", "D", "E", "F",
				  "G", "H", "I", "J", "K", "L", "M", "N",
				  "O", "P", "Q", "R", "S", "T", "U", "V",
				  "W", "X", "Y", "Z", "a", "b", "c", "d",
				  "e", "f", "g", "h", "i", "j", "k", "l",
				  "m", "n", "o", "p", "q", "r", "s", "t", 
				  "u", "v", "w", "x", "y", "z", ".", "&"];
var layer = 0;

function WordGen()
{
    var start_x = parseInt(interface.prompt("input the (hex) x position to start generating string graphic.", 0), 16);
	var start_y = parseInt(interface.prompt("input the (hex) y position to start generating string graphic.", 0), 16);
	var string_width = parseInt(interface.prompt("input the max width of the string graphic.", 0));
	var str = interface.prompt("input the string.", "type something here");
	str = str + " "
	var strlen = str.length;
	var layerwidth = interface.GetCurRoomLayerWidth(layer)
	var layerheight = interface.GetCurRoomLayerHeight(layer)

	var str_split = str.split(" ")
	for (let index = 0; index < str_split.length; index++) {
		if (str_split[index].length > string_width)
		{
			interface.log("there is at least one word lengthier than the string width you just set.")
			interface.log("word generation failed.")
			return;
		}
	}

	if ((start_x + string_width) > layerwidth)
		return;
	// don't want to care about this, the height will stretch
	// var strheight = Math.ceil(strlen / string_width) + ((strlen % string_width) ? 1 : 0);
	// if ((start_y + strheight) > layerwidth)
	// 	return;

	var finish = 0;
	var counter = 0;
	var letter_x_in_word = [];
	var letter_y_in_word = [];

	for (let v = start_y; v < layerheight && finish == 0; v++)
	{
		for (let h = start_x; h < (start_x + string_width) && finish == 0; h++)
		{
			for (let i = 0; i < letter_map.length; i++)
			{
				if (letter_map[i] == str[counter])
				{
					interface.SetCurRoomTile16(layer, i + base_offset, h, v);
					letter_x_in_word.push(h);
					letter_y_in_word.push(v);
					break;
				}
				else if (str[counter] == " ")
				{
					interface.SetCurRoomTile16(layer, 0, h, v);
					letter_x_in_word.length = 0;
					letter_y_in_word.length = 0;
				}
			}
			counter++;

			if (counter > strlen)
			{
				finish = 1;
			}
		}

		if (letter_x_in_word.length != 0)
		{
			var curlen = letter_x_in_word.length;
			counter -= curlen;
			for (let index = 0; index < curlen; index++)
			{
				interface.SetCurRoomTile16(layer, 0, letter_x_in_word[index], letter_y_in_word[index]);
			}
			letter_x_in_word.length = 0;
			letter_y_in_word.length = 0;
		}
	}

    interface.UpdateRoomGFXFull();
    interface.log("Finish generation !");
}

WordGen();
