while true do
	gui.text(0, 0, tostring(bizstring.hex(memory.readbyte(0x03001898))), 0xFFFF0000, topleft)
	gui.text(30, 0, tostring(bizstring.hex(memory.readbyte(0x03001899))), 0xFFFF0000, topleft)
	gui.text(60, 0, tostring(bizstring.hex(memory.readbyte(0x030018D5))), 0xFFFF0000, topleft)
	emu.frameadvance()
end