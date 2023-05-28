# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_reader_newtest'

module.SOURCE = [
    'reader_newtest.cpp',
    'tktusbrepeater.cpp',
    {
        'impl' : [
            'socket_mock.cpp',
        ],
    },
]
