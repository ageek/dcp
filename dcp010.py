#dcp-010

import threading
from time import sleep

class scheduler:
    def __init__(self):
        pass
    
    def delay(self, f, n):
        def sleep_then_call(n):
            sleep(n/1000)
            f()
        t = threading.Thread(target=sleep_then_call)
        t.start()
        
def f():
    print("finally called...")
    
scheduler.delay(f, 200,5)