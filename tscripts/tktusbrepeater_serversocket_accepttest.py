# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_serversocket_accepttest'

module.SOURCE = [
    'serversocket_accepttest.cpp',
    'serversocket.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
