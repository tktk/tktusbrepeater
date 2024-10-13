# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'libtktusbrepeater',
    'tktusbrepeater_commandlineoptions_initializetest',
    'tktusbrepeater_usbdevicemanager_newtest',
    'tktusbrepeater_usbdevicemanager_callbackusbhotplugtest',
    'tktusbrepeater_usbdevicemanager_bulktransfertest',
    'tktusbrepeater_serversocket_newtest',
    'tktusbrepeater_serversocket_accepttest',
    'tktusbrepeater_serversocket_pollintest',
    'tktusbrepeater_socket_newtest',
    'tktusbrepeater_socket_readtest',
    'tktusbrepeater_socket_writetest',
    'tktusbrepeater_socket_isconnectedtest',
    'tktusbrepeater_socket_pollintest',
    'tktusbrepeater_socket_pollouttest',
    'tktusbrepeater_usbendpointmanager_registerendpointtest',
    'tktusbrepeater_usbendpointmanager_unregisterertest',
    'tktusbrepeater_usb_isusbendpointouttest',
    'tktusbrepeater_repeat_readendpointtest',
    'tktusbrepeater_repeat_repeattousbdevicetest',
    'tktusbrepeater_repeat_repeatfromusbdevicetest',
]

module.BUILDER = cpp.program

module.TARGET = 'tktusbrepeater'

module.SOURCE = [
    'main.cpp',
    'commandlineoptions.cpp',
    'usbdevicemanager.cpp',
    'serversocket.cpp',
    'socket.cpp',
    'usbendpointmanager.cpp',
    'usb.cpp',
    'repeat.cpp',
    {
        'impl' : [
            'usb_libusb.cpp',
            'socket_unixsocket.cpp',
        ],
        'thread' : [
            'usbeventhandlingthread.cpp',
            'serversocketthread.cpp',
            'repeatthread.cpp',
            'repeatthreads.cpp',
            'endmanager.cpp',
            'joiner.cpp',
        ],
    },
]

module.LIB = [
    'usb-1.0',
]
