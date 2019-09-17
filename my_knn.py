#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/9/11 14:07
# @Author  : MengnanChen
# @File    : my_knn.py
# @Software: PyCharm

from collections import Counter
import numpy as np


class KNN:
    def __init__(self, k):
        self.k_ = k

    def predict(self, x_train, y_train, x_test):
        assert len(x_train.shape) == len(x_test.shape)
        assert len(y_train.shape) == 1
        classifications = []
        for point in x_test:
            distances = [np.linalg.norm(feature - point) for feature in x_train]
            distances_labels = list(zip(distances, y_train))
            distances_labels = sorted(distances_labels, key=lambda x: x[0])[:self.k_]
            topk_labels = [x[1] for x in distances_labels]
            topk_label = Counter(topk_labels).most_common(1)[0][0]
            classifications.append(topk_label)
        return classifications


if __name__ == '__main__':
    x_train = np.asarray([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ])
    y_train = np.asarray(
        [1, 2, 3]
    )
    x_test = np.asarray([
        [1, 2, 2]
    ])
    knn = KNN(1)
    print(knn.predict(x_train, y_train, x_test))
