# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'tktusbrepeater_usbdevicemanager_newtest',
    'tktusbrepeater_usbdevicemanager_callbackusbhotplugtest',
]

module.BUILDER = cpp.program

module.TARGET = 'tktusbrepeater'

module.SOURCE = [
    'main.cpp',
]
