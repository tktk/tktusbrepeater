# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'libtktusbrepeater_reader_readtest'

module.SOURCE = [
    {
        'lib' : [
            'reader_readtest.cpp',
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
