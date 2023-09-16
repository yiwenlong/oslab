def simple_generator():
    x = yield 1
    yield x + 10

gen = simple_generator()

next_val = next(gen)
print(next_val)

send_val = gen.send(20)
print(send_val)

try:
    gen.send(42)
except StopIteration as e:
    print("Generator is finished.")