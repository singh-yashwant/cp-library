def mod_power(b, p, mod):
    if p == 0:
        return 1
    temp = mod_power(b, p//2, mod)
    if p % 2 == 0:
        return (temp * temp) % mod
    else:
        return (b * temp * temp) % mod
