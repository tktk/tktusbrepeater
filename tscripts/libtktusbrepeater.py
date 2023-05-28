# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'libtktusbrepeater_reader_newtest',
    'libtktusbrepeater_reader_readtest',
    'libtktusbrepeater_writer_newtest',
    'libtktusbrepeater_writer_writetest',
]

module.BUILDER = cpp.shlib

module.TARGET = 'tktusbrepeater'

module.SOURCE = {
    'lib' : [
        'tktusbrepeater.cpp',
    ],
}
