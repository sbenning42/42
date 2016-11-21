import subprocess, MuseClient, MuseKeys,time

def main():
    #Muse single values you want to subscribe to.
    subscription = MuseKeys.MuseKeys
    length = len(subscription)
    
    #Instanciate and start MuseClient. MuseClient raise a MuseClientError on error
    try:
        client = MuseClient.MuseClient()
    except MuseClient.MuseClientError as error:
        print error
        return
    print 'Muse Instanciate'
    try:
        client.start()
    except MuseClient.MuseClientError as error:
        print error
        return
    print 'Muse started'
    
    #Subscribe method the count of successfull subscription
    #Once subscribe MuseInfo value is real-time updated
    if client.subscribe(subscription) < length:
        print 'Subscription error'
        #Stop the Producer thread
        client.stop()
        return
    
    now = time.time()
    while time.time() < now + 60:
        subprocess.call(['clear'])
        print client._muse_info.is_good.chan1, client._muse_info.is_good.chan2, client._muse_info.is_good.chan3, client._muse_info.is_good.chan4
        print client._muse_info.blink
        print client._muse_info.batt.SoC, client._muse_info.batt.FGv, client._muse_info.batt.ADCv, client._muse_info.batt.temp
        print client._muse_info.jaw_clench
        time.sleep(0.1)
    
    #Unsubscribe method return the count of successfull unsubscription
    #Once unsubscribe MuseInfo value is reset to None
    if client.unsubscribe(subscription) < length:
        print 'Unsubscription error'
    client.stop()
    print 'Exit'

if __name__ == '__main__':
    main()
