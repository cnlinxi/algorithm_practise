#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/9/11 13:41
# @Author  : MengnanChen
# @File    : my_cnn.py
# @Software: PyCharm

import numpy as np


def compute_conv(feature_map, kernel):
    h, w = feature_map.shape
    k, _ = kernel.shape
    r = k // 2

    padding_fm = np.zeros(shape=(h + 2, w + 2),dtype=np.float32)
