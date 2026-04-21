n = int(input("Enter number of processes: "))

processes = []

for i in range(n):
    at, bt, pr = map(int, input(f"P{i+1} (AT BT Priority): ").split())
    processes.append({
        "pid": i + 1,
        "at": at,
        "bt": bt,
        "pr": pr,
        "ct": 0,
        "tat": 0,
        "wt": 0
    })

time = 0
completed = []

while processes:
    ready = [p for p in processes if p["at"] <= time]

    if not ready:
        time += 1
        continue

    current = max(ready, key=lambda x: x["pr"])

    time += current["bt"]
    current["ct"] = time
    current["tat"] = current["ct"] - current["at"]
    current["wt"] = current["tat"] - current["bt"]

    completed.append(current)
    processes.remove(current)

print("\nPID AT BT PR CT TAT WT")
for p in sorted(completed, key=lambda x: x["pid"]):
    print(p["pid"], p["at"], p["bt"], p["pr"],
          p["ct"], p["tat"], p["wt"])

avg_tat = sum(p["tat"] for p in completed) / n
avg_wt = sum(p["wt"] for p in completed) / n

print("\nAverage TAT:", round(avg_tat, 2))
print("Average WT :", round(avg_wt, 2))