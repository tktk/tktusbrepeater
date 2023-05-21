# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

#module.DEPENDS = [
#]

module.BUILDER = cpp.shlib

module.TARGET = 'tktusbrepeater'

module.SOURCE = {
    'lib' : [
        'tktusbrepeater.cpp',
    ],
}
