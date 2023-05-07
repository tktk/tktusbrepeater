# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_serversocket_newtest'

module.SOURCE = [
    'serversocket_newtest.cpp',
    'serversocket.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
