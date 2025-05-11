import time


Import("env")

def after_upload(source, target, env):
    port = env.GetProjectOption("monitor_port")
    print("waiting for " + port + " ...")
    # time.sleep(5)
    
    import serial
    while True:
        try:
            s = serial.Serial(port)
            break
        except:
            pass

env.AddPostAction("upload", after_upload)