# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_socket_pollintest'

module.SOURCE = [
    'socket_pollintest.cpp',
    'socket.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
