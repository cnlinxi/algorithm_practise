#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/9/11 14:30
# @Author  : MengnanChen
# @File    : my_auc.py
# @Software: PyCharm

from sklearn.metrics import roc_curve, auc


def naive_auc(labels, predictions):
    pos_indexes = []
    neg_indexes = []
    for index, label in enumerate(labels):
        if label == 1:
            pos_indexes.append(index)
        elif label == 0:
            neg_indexes.append(index)
    auc = 0.
    for pos_index in pos_indexes:
        for neg_index in neg_indexes:
            if predictions[pos_index] > predictions[neg_index]:
                auc += 1
            elif predictions[pos_index] == predictions[neg_index]:
                auc += 0.5
    return auc / (len(neg_indexes) * len(pos_indexes))


if __name__ == '__main__':
    x = [1, 0, 0, 1, 0]
    y = [0.9, 0.8, 0.5, 0.6, 0.3]
    fpr, tpr, threadholds = roc_curve(x, y)
    print('naive auc: {}'.format(naive_auc(x, y)))
    print('sklearn auc: {}'.format(auc(fpr, tpr)))
