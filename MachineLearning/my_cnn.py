# -*- coding: utf-8 -*-
# @Time    : 2019/9/9 17:16
# @Author  : MengnanChen
# @FileName: my_cnn.py
# @Software: PyCharm

import numpy as np


def compute_conv(feature_map, kernel):
    h, w = feature_map.shape
    k, _ = kernel.shape
    r = k // 2

    padding_fm = np.zeros(shape=(h + 2, w + 2), dtype=np.float32)
    rst = np.zeros(shape=(h, w), dtype=np.float32)
    padding_fm[1:h + 1, 1:w + 1] = feature_map

    for i in range(1, h + 1):
        for j in range(1, w + 1):
            roi = padding_fm[i - r:i + r + 1][j - r:j + r + 1]
            rst[i - 1][j - 1] = np.sum(roi * kernel)

    return rst


def my_conv(inputs, weights):
    h, w, c = inputs.shape
    _, k, _ = weights.shape
    outputs = []
    output_c = 1

    for i in range(output_c):
        output_ = np.zeros(shape=[h, w], dtype=np.float32)
        for j in range(c):
            kernel = weights[j]
            feature_map = inputs[j]
            output_ += compute_conv(feature_map, kernel)

        outputs.append(output_)

    return outputs
