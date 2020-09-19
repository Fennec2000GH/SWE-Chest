# 09/ 11/ 2020

from sys import stdin, stdout
import copy
from typing import List
from decimal import Decimal


def kadane_product(it: List[Decimal]) -> None:
    global_max = local_max = local_min = copy.deepcopy(x=it[0])

    for element in it[1:]:
        # print(f'global_max: {global_max}, local_max: {local_max}, local_min: {local_min}')
        prev_local_max = local_max
        prev_local_min = local_min

        local_max = max([prev_local_max * element, prev_local_min * element, element])
        local_min = min([prev_local_max * element, prev_local_min * element, element])
        if local_max > global_max:
            global_max = local_max
    if str(global_max) == '-0':
        stdout.write('0\n')
    else:
        stdout.write(f'{str(global_max)}\n')


if __name__ == '__main__':
    it = list()
    while True:
        line = stdin.readline()
        # print(f'line: {line}')
        it.extend(line.split(' '))
        it[-1] = it[-1][:-1]
        if it[len(it) - 1] == '-999999':
            it.pop()
            it = [Decimal(element) for element in it]
            # print(f'Decimal it: {it}')
            kadane_product(it)
            # print(Decimal(10**600))
            it.clear()
