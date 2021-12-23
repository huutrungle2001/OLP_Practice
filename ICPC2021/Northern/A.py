file_name = input().split('.')

tail = file_name[len(file_name) - 1].lower()

if len(file_name) >= 2 and tail == 'py':
    print("yes")
else:
    print("no")
