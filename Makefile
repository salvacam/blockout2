all:
	make -C ImageLib/src/
	make -C VTinyGL/
	make -C BlockOut/

ipk: all
	@rm -rf /tmp/.blockout2-ipk/ && mkdir -p /tmp/.blockout2-ipk/root/home/retrofw/games/blockout2 /tmp/.blockout2-ipk/root/home/retrofw/apps/gmenu2x/sections/games
	@cp -r blockout2/images blockout2/sounds blockout2/blockout2.elf blockout2/blockout2.png /tmp/.blockout2-ipk/root/home/retrofw/games/blockout2
	@cp blockout2/blockout2.lnk /tmp/.blockout2-ipk/root/home/retrofw/apps/gmenu2x/sections/games
	@sed "s/^Version:.*/Version: $$(date +%Y%m%d)/" blockout2/control > /tmp/.blockout2-ipk/control
	@cp blockout2/conffiles /tmp/.blockout2-ipk/
	@tar --owner=0 --group=0 -czvf /tmp/.blockout2-ipk/control.tar.gz -C /tmp/.blockout2-ipk/ control conffiles
	@tar --owner=0 --group=0 -czvf /tmp/.blockout2-ipk/data.tar.gz -C /tmp/.blockout2-ipk/root/ .
	@echo 2.0 > /tmp/.blockout2-ipk/debian-binary
	@ar r blockout2/blockout2.ipk /tmp/.blockout2-ipk/control.tar.gz /tmp/.blockout2-ipk/data.tar.gz /tmp/.blockout2-ipk/debian-binary
