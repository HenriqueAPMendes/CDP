import json
import random
import sys

def markAsDone(url):
    with open('problems.json', 'r') as file:
        data = json.load(file)

    undone = data['undone']
    done = data['done']

    for obj in undone:
        if obj['url'] == url:
            undone.remove(obj)
            done.append(obj)
            break
    else:
        print(f"Problem '{url}' not found.")
        return

    with open('problems.json', 'w') as file:
        json.dump(data, file, indent=2)

    print(f"Marked problem '{url}' as 'done'.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 markasdone.py <url>")
        sys.exit(1)

    url_to_move = sys.argv[1]
    markAsDone(url_to_move)
