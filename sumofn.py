t = int(input())         
results = []

for _ in range(t):
    n = int(input())
    results.append(n * (n + 1) // 2)

print("\n".join(map(str, results))) 
