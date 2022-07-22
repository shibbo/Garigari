import csv, glob, math, os, sys
from pathlib import Path


def truncate(number, digits) -> float:
    stepper = 10.0 ** digits
    return math.trunc(stepper * number) / stepper

full_game_size = 0
done_game_size = 0

with open("data/funcs.csv", "r") as f:
    lines = f.readlines()

    for line in lines:
        if "Symbol" in line:
            continue

        spl = line.split(",")
        sym = spl[0]
        size = int(spl[2], 16)
        match = spl[3].strip("\r\n")

        if match == "true":
            done_game_size += size

        full_game_size += size

print("Calculating percentages...")

progPercent = (done_game_size / full_game_size ) * 100.0
progNonPercent = int((done_game_size / full_game_size) * 120.0)

print(f"Progress: {progPercent}% [{done_game_size} / {full_game_size}] bytes")
print(f"You currently have {progNonPercent} / 120 stars.")
print("Generating JSON...")

json = []
json.append("{\n")
json.append("\t\"schemaVersion\": 1,\n")
json.append(f"\t\"label\": \"game\",\n")
json.append(f"\t\"message\": \"{progPercent}%\",\n")
json.append(f"\t\"color\": \"blue\"\n")
json.append("}")

with open(f"data/game.json", "w") as w:
    w.writelines(json)

print("Done.")