class Item:
    def __init__(self, key: int, data: str):
        self.key = key
        self.data = data

    def __repr__(self):
        return f'{self.key}: {self.data}'


def sort_items(e):
    return e.key


if __name__ == "__main__":
    items = []
    items.append(Item(2, "asdfgh"))
    items.append(Item(1, "qwerty"))
    print(items)

    items.sort(key=sort_items)
    print("")
    print(items)