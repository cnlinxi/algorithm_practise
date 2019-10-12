#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/9/11 13:42
# @Author  : MengnanChen
# @File    : my_kmeans.py
# @Software: PyCharm

from copy import deepcopy
import numpy as np


class KMeans:
    def __init__(self, k, tolerance=1e-3, n_iteration=300):
        self.k_ = k
        self.tolerance_ = tolerance
        self.n_iteration_ = n_iteration

    def fit(self, data):
        assert data.shape[0] >= self.k_
        self.centers_ = {}
        self.clf_ = {}
        for i in range(self.k_):
            self.centers_[i] = data[i]
            self.clf_[i] = []
        for _ in range(self.n_iteration_):
            for point in data:
                distances = [np.linalg.norm(point - center) for center in self.centers_]
                self.clf_[distances.index(min(distances))].append(point)
            prev_centers = deepcopy(self.centers_)
            for i in range(self.k_):
                self.centers_[i] = np.average(self.clf_[i], axis=0)
            center_tolerance = 0.
            for i in range(self.k_):
                center_tolerance += abs(np.sum(prev_centers[i] - self.centers_[i]))
            if center_tolerance < self.tolerance_:
                break

    def predict(self, points):
        clusters = []
        for point in points:
            distances = [np.linalg.norm(point, center) for center in self.centers_]
            clusters.append(distances.index(min(distances)))
        return clusters


if __name__ == '__main__':
    x = np.asarray([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ])
    kmeans = KMeans(k=2)
    kmeans.fit(x)
    print(kmeans.centers_)
