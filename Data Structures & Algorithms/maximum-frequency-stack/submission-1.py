class FreqStack:
    def __init__(self):
        # Maps value -> its current frequency
        self.freq = {}
        # Maps frequency -> stack of values with that frequency
        self.group = {}
        # Tracks the current highest frequency in the entire structure
        self.max_freq = 0

    def push(self, val: int) -> None:
        # 1. Update the frequency of the value
        f = self.freq.get(val, 0) + 1
        self.freq[val] = f
        
        # 2. Update max_freq if this is a new record
        if f > self.max_freq:
            self.max_freq = f
            
        # 3. Add the value to the stack corresponding to its current frequency
        if f not in self.group:
            self.group[f] = []
        self.group[f].append(val)

    def pop(self) -> int:
        # 1. Get the top element from the highest frequency stack
        val = self.group[self.max_freq].pop()
        
        # 2. Decrement the frequency of that value in our map
        self.freq[val] -= 1
        
        # 3. If the highest frequency stack is now empty, move the pointer down
        if not self.group[self.max_freq]:
            self.max_freq -= 1
            
        return val