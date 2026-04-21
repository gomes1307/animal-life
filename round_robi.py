n = int(input("Enter number of processes: "))
tq = int(input("Enter Time Quantum: "))

processes = []

for i in range(n):
    at, bt = map(int, input(f"P{i+1} (AT BT): ").split())
    processes.append({
        "pid": i + 1,
        "at": at,
        "bt": bt,
        "rt": bt,
        "ct": 0,
        "tat": 0,
        "wt": 0
    })

time = 0
queue = []
completed = 0

while completed < n:
    for p in processes:
        if p["at"] == time:
            queue.append(p)

    if not queue:
        time += 1
        continue

    current = queue.pop(0)

    execute = min(tq, current["rt"])
    current["rt"] -= execute
    time += execute

    for p in processes:
        if p["at"] > time - execute and p["at"] <= time:
            queue.append(p)

    if current["rt"] > 0:
        queue.append(current)
    else:
        current["ct"] = time
        current["tat"] = current["ct"] - current["at"]
        current["wt"] = current["tat"] - current["bt"]
        completed += 1

print("\nPID AT BT CT TAT WT")
for p in sorted(processes, key=lambda x: x["pid"]):
    print(p["pid"], p["at"], p["bt"], p["ct"], p["tat"], p["wt"])

avg_tat = sum(p["tat"] for p in processes) / n
avg_wt = sum(p["wt"] for p in processes) / n

print("\nAverage TAT:", round(avg_tat, 2))
print("Average WT :", round(avg_wt, 2))