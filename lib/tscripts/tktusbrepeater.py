# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'tktusbrepeater_reader_newtest',
]

module.BUILDER = cpp.shlib

module.TARGET = 'tktusbrepeater'

module.SOURCE = [
    'tktusbrepeater.cpp',
]