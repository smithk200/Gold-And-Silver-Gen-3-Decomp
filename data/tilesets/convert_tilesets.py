#!/usr/bin/python3

from sys import argv
import os, subprocess, struct


NUM_TILES_IN_PRIMARY = 640
NUM_TILES_TOTAL = 1024
NUM_METATILES_IN_PRIMARY = 640
NUM_METATILES_TOTAL = 1024

def create_new_behavior(path):
    file = path + '/metatile_attributes.bin'
    num = int(os.path.getsize(file) / 4)
    
    with open(file, 'rb') as f:
        new_data = bytearray(num * 2)
        data = f.read(num * 4)
        for i in range(0, num):
            behavior = data[i * 4]
                    
            new_data[i * 2] = behavior
            bg = data[i * 4 + 3]
            if bg & 0x20 == 0x20:
                bg = 0x10
            new_data[i * 2 + 1] = bg

    with open(os.sep.join([path, 'metatile_attributes_new.bin']), 'wb+') as f:
        f.write(new_data)

# copy fire red tilesets over
if not os.path.isdir('data/tilesets/secondary/berry_forest/'):
	path = '../../firered/pokefirered/data/tilesets/secondary'
	dirs = os.listdir(path)
	for dir in dirs:
		if os.path.isfile(path + '/' + dir + '/tiles.png'):
			str = 'cp -a ' + path + '/' + dir + ' ../../emerald/pokeemerald/data/tilesets/secondary/.';
			print(str)
			os.system(str)

# convert metatile attributes
path = './data/tilesets/secondary/'
dirs = os.listdir(path)
for i in dirs:
	if os.path.isfile(path + i + '/tiles.png'):
		print('create_new_behavior(' + path + i + '/)')
		create_new_behavior(path + i)
