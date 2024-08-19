#!/usr/bin/python
# -*- coding: utf8 -*-
#
# Create on: 2024-01-30
#    Author: fasiondog

class EasyTraderOrderBroker:
    def __init__(self, user):
        self.user = user

    def buy(self, code, price, num, stoploss, goal_price, part_from):
        self.user.buy(code[2:], price=price, amount=num)
        print("买入：%s  %.3f  %i" % (code, price, num))

    def sell(self, code, price, num, stoploss, goal_price, part_from):
        self.user.sell(code[2:], price=price, amount=num)
        print("卖出：%s  %.3f  %i" % (code, price, num))

    def cash(self):
        balance = self.user.balance
        ret = 0.0
        for i in range(len(balance)):
            ret += balance[i]['可用资金']
        return ret
