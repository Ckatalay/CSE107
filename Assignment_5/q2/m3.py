a = [46.45, 44.38, 52.65, 54.10]
f = [10.78, 12.74, 14.70, 16.66]
f = [i * 1000 for i in f]
af = [a[i] * f[i] for i in range(len(a))]
asq = [i ** 2 for i in a]


a_sum = 197.6
f_sum = 54880
sum_af = 2741000
sum_asq = 9826


num = (4 * sum_af) - (a_sum * f_sum)
deno = (4 * sum_asq) - (a_sum ** 2)
result = num / deno


print(f"a sum = {a_sum}\nf_sum = {f_sum}\nsum_af = {sum_af}\nsum_asq = {sum_asq}\nresult = {result}")