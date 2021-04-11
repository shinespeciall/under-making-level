function AddWindEventTile()
{
    width = interface.GetCurRoomLayerWidth(1);
    height = interface.GetCurRoomLayerHeight(1);

    for (y = 0; y < parseInt(height); y++)
	{
        for (x = 0; x < parseInt(width); x++)
		{
			if(interface.GetCurRoomTile16(0, x, y) == 31)
			{
				interface.SetCurRoomTile16(1, 188, x, y);
			}
		}
	}

    interface.UpdateRoomGFXFull();
    interface.log("Finish generation !");
}

AddWindEventTile();
