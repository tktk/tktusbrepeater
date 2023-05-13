# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_socket_readtest'

module.SOURCE = [
    'socket_readtest.cpp',
    'socket.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
