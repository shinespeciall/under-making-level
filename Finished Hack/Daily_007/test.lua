while true do
    local MapSw0 = memory.readbyte(0x300002E)
    local MapSw1 = memory.readbyte(0x300002F)
    local MapSw2 = memory.readbyte(0x3000030)
    local MapSw3 = memory.readbyte(0x3000031)
    local MapSw4 = memory.readbyte(0x3000032)
    gui.text(90, 16, tostring(bizstring.hex(MapSw0)), 0xFFFF0000, topleft)
    gui.text(120, 16, tostring(bizstring.hex(MapSw1)), 0xFFFF0000, topleft)
    gui.text(150, 16, tostring(bizstring.hex(MapSw2)), 0xFFFF0000, topleft)
    gui.text(180, 16, tostring(bizstring.hex(MapSw3)), 0xFFFF0000, topleft)
    gui.text(210, 16, tostring(bizstring.hex(MapSw4)), 0xFFFF0000, topleft)
	emu.frameadvance()
end