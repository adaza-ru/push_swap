# 42_Push_Swap
42 Push Swap
ARG=$(shuf -e $(seq 1 500) | awk -v min=-2147483648 -v max=2147483647 'BEGIN{srand();}{print int(min + rand() * (max - min + 1))}' | tr '\n' ' ')
valgrind --leak-check=full ./push_swap $ARG | wc -l