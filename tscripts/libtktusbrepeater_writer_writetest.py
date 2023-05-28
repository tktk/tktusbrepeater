# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'libtktusbrepeater_writer_writetest'

module.SOURCE = [
    {
        'lib' : [
            'writer_writetest.cpp',
            'tktusbrepeater.cpp',
            {
                'impl' : [
                    'socket_mock.cpp',
                ],
            },
        ],
    },
    'usb.cpp',
]
