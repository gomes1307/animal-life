n = int(input("Enter number of processes: "))

processes = []

for i in range(n):
    at, bt = map(int, input(f"P{i+1} (AT BT): ").split())
    processes.append({
        "pid": i + 1,
        "at": at,
        "bt": bt,
        "ct": 0,
        "tat": 0,
        "wt": 0
    })
processes.sort(key=lambda x: x["at"])

time = 0

for p in processes:
    if time < p["at"]:
        time = p["at"]

    time += p["bt"]
    p["ct"] = time
    p["tat"] = p["ct"] - p["at"]
    p["wt"] = p["tat"] - p["bt"]

print("\nPID AT BT CT TAT WT")
for p in sorted(processes, key=lambda x: x["pid"]):
    print(p["pid"], p["at"], p["bt"], p["ct"], p["tat"], p["wt"])

avg_tat = sum(p["tat"] for p in processes) / n
avg_wt = sum(p["wt"] for p in processes) / n

print("\nAverage TAT:", round(avg_tat, 2))
print("Average WT :", round(avg_wt, 2))