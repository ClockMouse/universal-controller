for tty in /dev/ttyUSB*; do
	sudo minicom -c on --device $tty --baud 9600
done