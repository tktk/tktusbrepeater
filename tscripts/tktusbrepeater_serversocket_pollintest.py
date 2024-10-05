# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_serversocket_pollintest'

module.SOURCE = [
    'serversocket_pollintest.cpp',
    'serversocket.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
