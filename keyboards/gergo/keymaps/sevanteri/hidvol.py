import os
import hid


# TODO: listen for when devices are connected
# TODO: loop through interfaces and ask them some specific and make kb return something

d = hid.Device(
    path=next(
        dev
        for dev in hid.enumerate(0xFEED, 0x1307)
        if dev['interface_number'] == 1
    )['path']
)


while True:
    msg = ((d.read(8).decode()))
    if msg.startswith('VOL:'):
        split = msg.split(':')
        y = int(split[-1])
        if y > 0:
            os.system(f'pactl set-sink-volume @DEFAULT_SINK@ {y:+}%')
        elif y < 0:
            os.system(f'pactl set-sink-volume @DEFAULT_SINK@ {y:+}%')

