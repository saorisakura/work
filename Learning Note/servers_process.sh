#!/usr/bin/env bash
# Author: Xavier
export LANG=en_US.UTF-8
export PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin:/root/bin:/root/bin

udp2rtmp_reload_path_r="/usr/local/udp2rtmp-master/"
udp2rtmp_reload_path_w="/usr/local/work/"
lm_proxy_reload_path="/usr/local/lm_proxy/"
channel_proxy_reload_path="/usr/local/dlproxy/"

# Var Definition
NOW=$(date +%F\ %H:%M)
udpDir="udpvideo"
gateDir="gateway"
echoDir="echoServer"
checkDir="CheckServer"
rgwDir="rgwServer"
rtuDir="RTU"
watchGWDir="WATCH_GW"
watchRDir="WATCH_R"
RDir="PULL_R"
grabDir="grab"
secProcess="duhttp"
udpProcess="realrelayserver"
gateProcess="gatewayserver"
echoProcess="EchoServer"
checkProcess="CheckServer"
rgwProcess="RGWServer"
watchrProcess="watchr"
watchgwProcess="watchgw"
rtuProcess="GatewayRTU"
grabProcess="grabserver"

CHANNELPROC="channel_proxy"
CHANNELPROC_EN="channel_proxy_en"

LMProcess="lm_proxyserver"

# Sys config
ulimit -c unlimited

# Functions
function outputFinally(){
    ps -ef|grep -E "gatewayserver|realrelayserver|duhttp|CheckServer|EchoServer|RGWServer|watchr|watchgw|GatewayRTU|grabserver|channel_proxy|lm_proxyserver"|grep -v grep
}

# UDP2RTMP related
function checkDirs(){
    parentDir="/tmp/udp2rtmp"
    mkdir $parentDir/$udpDir -p 2> /dev/null
    mkdir $parentDir/$gateDir -p 2> /dev/null
    mkdir $parentDir/$echoDir -p 2> /dev/null
    mkdir $parentDir/$rgwDir -p 2> /dev/null
    mkdir $parentDir/$checkDir -p 2> /dev/null
    mkdir $parentDir/R -p 2> /dev/null
    mkdir $parentDir/watchgw -p 2> /dev/null
    mkdir $parentDir/WATCH_R -p 2> /dev/null
    mkdir $parentDir/RTU -p 2> /dev/null
    id wowza > /dev/null 2>&1
    if [ $? -eq 0 ];then
        chown -R wowza.wowza $parentDir 2> /dev/null
    else
        useradd wowza
        chown -R wowza.wowza $parentDir 2> /dev/null
    fi
}

function stopGrabserver(){
    echo "stop grabserver......"
    ps -ef|grep $grabProcess |grep -v grep |grep -v 'grabserver-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startGrabserver(){
    if [ -d $udp2rtmp_reload_path_r/$grabDir ];then
        echo "start Grabserver......"
        cd $udp2rtmp_reload_path_r/$grabDir
        nohup ./$grabProcess config_5011.xml > /dev/null 2>&1 &
        nohup ./$grabProcess config_2011.xml > /dev/null 2>&1 &
        nohup ./$grabProcess config_4011.xml > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of Grabserver..."
    fi
}

function stopRTU(){
    echo "stop GatewayRTU......"
    ps -ef|grep $rtuProcess |grep -v grep |grep -v 'GatewayRTU-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startRTU(){
    if [ -d $udp2rtmp_reload_path_r/$rtuDir ];then
        echo "start GatewayRTU......"
        cd $udp2rtmp_reload_path_r/$rtuDir
        nohup ./$rtuProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of GatewayRTU..."
    fi
}

function stopWatchR(){
    echo "stop watchr......"
    ps -ef|grep $watchrProcess |grep -v grep |grep -v '$watchrProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function stopWatchGW(){
    echo "stop watchgw......"
    ps -ef|grep $watchgwProcess |grep -v grep |grep -v '$watchgwProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startWatchRGW(){
    if [ -d $udp2rtmp_reload_path_r/$watchGWDir ] && [ -d $udp2rtmp_reload_path_r/$watchRDir ];then
        echo "start watchr and watchgw......"
        cd $udp2rtmp_reload_path_r/$watchGWDir
        nohup ./$watchgwProcess > /dev/null 2>&1 &
        cd $udp2rtmp_reload_path_r/$watchRDir
        nohup ./$watchrProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of WATCH_GW or WATCH_R..."
    fi
}

function stopDuhttp(){
    echo "stop duhttp......"
    ps -ef|grep $secProcess |grep -v grep |grep -v '$secProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null 
}

function startDuhttp(){
    if [ -d $udp2rtmp_reload_path_r/$udpDir ];then
        echo "start duhttp......"
        cd $udp2rtmp_reload_path_r/$udpDir
        nohup ./$secProcess > /dev/null 2>&1 &
        cd ..
     else
        echo "no such dir of udpvideo..."
     fi
}

function startDuhttp_w(){
    if [ -d $udp2rtmp_reload_path_w/$RDir ];then
        echo "start duhttp......"
        cd $udp2rtmp_reload_path_w/$RDir
        nohup ./$secProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of udpvideo..."
    fi
}

function stopRealrelayServer(){
    echo "stop realrelayserver....."
    ps -ef|grep $udpProcess |grep -v grep |grep -v '$udpProcess-' |awk '{print $2}' |xargs kill -USR2 2> /dev/null
}

function startRealrelayServer(){
    if [ -d $udp2rtmp_reload_path_r/$udpDir ];then
        echo "start realrelayserver......"
        cd $udp2rtmp_reload_path_r/$udpDir
        nohup ./$udpProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of udpvideo..."
    fi
}

function startRealrelayServer_w(){
    if [ -d $udp2rtmp_reload_path_w/$RDir ];then
        echo "start realrelayserver......"
        cd $udp2rtmp_reload_path_w/$RDir
        nohup ./$udpProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of udpvideo..."
    fi
}

function stopGatewayServer(){
    echo "stop gatewayserver......"
    ps -ef|grep gatewayserver |grep -v grep |grep -v 'gatewayserver-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startGatewayServer(){
    if [ -d $udp2rtmp_reload_path_r/$gateDir ];then
        echo "start gatewayserver......"
        cd $udp2rtmp_reload_path_r/$gateDir
        nohup ./$gateProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of gateway..."
    fi
}

function startGatewayServer_w(){
    if [ -d $udp2rtmp_reload_path_w/$gateDir ];then
        echo "start gatewayserver......"
        cd $udp2rtmp_reload_path_w/$gateDir
        nohup ./$gateProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of gateway..."
    fi
}

function stopCheckServer(){
    echo "stop checkserver......"
    ps -ef|grep $checkProcess |grep -v grep |grep -v '$checkProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startCheckServer(){
    if [ -d $udp2rtmp_reload_path_r/$checkDir ];then
        echo "start checkserver......"
        cd $udp2rtmp_reload_path_r/$checkDir
        nohup ./$checkProcess > /dev/null 2>&1 &
        cd ..
    else
        echo  "no such dir of CheckServer..."
    fi
}

function stopRGWServer(){
    echo "stop rgwserver......"
    ps -ef|grep $rgwProcess |grep -v grep |grep -v '$rgwProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startRGWServer(){
    if [ -d $udp2rtmp_reload_path_r/$rgwDir ];then
        echo "start rgwserver......"
        cd $udp2rtmp_reload_path_r/$rgwDir
        nohup ./$rgwProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of rgwServer..."
    fi
}

function stopEchoServer(){
    echo "stop echoserver......"
    ps -ef|grep $echoProcess |grep -v grep |grep -v '$echoProcess-' |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function startEchoServer(){
    if [ -d $udp2rtmp_reload_path_r/$echoDir ];then
        echo "start echoserver......"
        cd $udp2rtmp_reload_path_r/$echoDir
        nohup ./$echoProcess > /dev/null 2>&1 &
        cd ..
    else
        echo "no such dir of echoServer..."
    fi
}

# channel_proxy related
function stop_channel_proxy_8000(){
    echo "stop channel_proxy 8000......"
    ps -ef|grep $CHANNELPROC |grep -v -E '8010|9010|9000' |grep -v grep |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function start_channel_proxy_8000(){
    echo "start channel_proxy 8000......"
	cd $channel_proxy_reload_path
    nohup ./$CHANNELPROC -f server_config.ini > /dev/null 2>&1 &
}


function stop_channel_proxy_9000(){
    echo "stop channel_proxy 9000......"
    ps -ef|grep $CHANNELPROC |grep '9000' |grep -v grep |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function start_channel_proxy_9000(){
    echo "start channel_proxy 9000......"
	cd $channel_proxy_reload_path
    nohup ./$CHANNELPROC -f server_config_9000.ini > /dev/null 2>&1 &
}

function stop_channel_proxy_8010(){
    echo "stop channel_proxy 8010......"
    ps -ef|grep $CHANNELPROC_EN |grep '8010' |grep -v grep |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function start_channel_proxy_8010(){
    echo "start channel_proxy 8010......"
	cd $channel_proxy_reload_path
    nohup ./$CHANNELPROC_EN -f server_config_8010.ini > /dev/null 2>&1 &
}

function stop_channel_proxy_9010(){
    echo "stop channel_proxy 9010......"
    ps -ef|grep $CHANNELPROC_EN |grep '9010' |grep -v grep |awk '{print $2}' |xargs kill -9 2> /dev/null
}

function start_channel_proxy_9010(){
    echo "start channel_proxy 9010......"
	cd $channel_proxy_reload_path
    nohup ./$CHANNELPROC_EN -f server_config_9010.ini > /dev/null 2>&1 &
}

# lian mai related
function lm_check(){
    if [ ! -d "/tmp/lm_proxy/" ];then
        mkdir /tmp/lm_proxy/
    fi
    if [ ! -x "$lm_proxy_reload_path/$Process" ];then
        chmod 755 $lm_proxy_reload_path/$LMProcess
    fi
    if [ ! -x "$lm_proxy_reload_path/lmproxylst.py" ];then
        chmod 755 $lm_proxy_reload_path/lmproxylst.py
    fi
}

function lm_stop(){
	ps axu|grep $LMProcess|grep -v grep |grep -v '-'|cut -c 9-15|xargs kill -9 2> /dev/null
}

function lm_start(){
        if [ -d "$lm_proxy_reload_path" ];then
                cd $lm_proxy_reload_path
                nohup ./$LMProcess config_4001.xml > /dev/null 2>&1 &
                nohup ./$LMProcess config_8001.xml > /dev/null 2>&1 &
        else
                echo -e "\033[31m$NOW [E] - No LM_PROXY Dir. \033[0m"
                return 2
        fi
        echo -e "\033[32m$NOW [I] - Start LM_PROXY ok. \033[0m"
        return 0
}

function lm_main(){
    lm_check
	lm_stop
	lm_start
}

# applications
function stopServers(){
    stopDuhttp
    stopRealrelayServer
    stopGatewayServer
    stopCheckServer
    stopRGWServer
    stopEchoServer
    stopWatchR
    stopWatchGW
    stopRTU
    stopGrabserver
	lm_stop
	stop_channel_proxy_8000
	stop_channel_proxy_8010
	stop_channel_proxy_9000
	stop_channel_proxy_9010
}

function startServers(){
	# record
    startDuhttp
    startRealrelayServer
    startGatewayServer
    startCheckServer
    startRGWServer
    startEchoServer
    startWatchRGW
    startRTU
    startGrabserver
	lm_start
	start_channel_proxy_8000
	start_channel_proxy_8010
	start_channel_proxy_9000
	start_channel_proxy_9010
}

function stopWatch(){
    stopDuhttp
    stopRealrelayServer
    stopGatewayServer
}

function startWatch(){
    startDuhttp_w
    startRealrelayServer_w
    startGatewayServer_w
}

# main
checkDirs
case $1 in
    stop)
        stopServers
        outputFinally
        ;;
    start_r)
        # record
        startServers
        outputFinally
        ;;
    start_w)
        # watch
        startWatch
        outputFinally
        ;;
    status)
        outputFinally
        ;;
    real)
	    # core record
        stopDuhttp
        stopRealrelayServer
        startDuhttp
        startRealrelayServer
        outputFinally
        ;;
    wreal)
        # watch
        stopRealrelayServer
        startRealrelayServer_w
        outputFinally
        ;;
    real_sec)
        # record
        stopDuhttp
        startDuhttp
        outputFinally
        ;;
    wreal_sec)
		# watch
        stopDuhttp
        startDuhttp_w
        outputFinally
        ;;
    gate)
		# record
        stopGatewayServer
        startGatewayServer
        outputFinally
        ;;
    wgate)
		# watch
        stopGatewayServer
        startGatewayServer_w
        outputFinally
        ;;
    check)
        stopCheckServer
        startCheckServer
        outputFinally
        ;;
    rgw)
	    # core and record
        stopRGWServer
        startRGWServer
        outputFinally
        ;;
    ech)
        stopEchoServer
        startEchoServer
        outputFinally
        ;;
    wrgw)
        stopWatchR
        stopWatchGW
        startWatchRGW
        outputFinally
        ;;
    rtu)
        stopRTU
        startRTU
        outputFinally
        ;;
    watch)
        stopWatch
        startWatch
        outputFinally
        ;;
    record)
        stopServers
        startServers
        outputFinally
        ;;
    core)
        # core only
        stopRealrelayServer
        stopRGWServer
        startRealrelayServer
        startRGWServer
        outputFinally
        ;;
    grab)
    	stopGrabserver
	    startGrabserver
	    outputFinally
	    ;;
    channel_all)
        stop_channel_proxy_8000
        stop_channel_proxy_9000
        stop_channel_proxy_8010
        stop_channel_proxy_9010
        start_channel_proxy_8000
        start_channel_proxy_9000
        start_channel_proxy_8010
        start_channel_proxy_9010
        ;;
    channel_stop)
        stop_channel_proxy_8000
        stop_channel_proxy_9000
        stop_channel_proxy_8010
        stop_channel_proxy_9010
        ;;
    channel_start)
        start_channel_proxy_8000
        start_channel_proxy_9000
        start_channel_proxy_8010
        start_channel_proxy_9010
        ;;
    channel_restart_8000)
        stop_channel_proxy_8000
        start_channel_proxy_8000
        ;;
    channel_restart_9000)
        stop_channel_proxy_9000
        start_channel_proxy_9000
        ;;
    channel_restart_8010)
        stop_channel_proxy_8010
        start_channel_proxy_8010
        ;;
    channel_restart_9010)
        stop_channel_proxy_9010
        start_channel_proxy_9010
        ;;
    lm_all)
        lm_main
        ;;  
    lm_stop)
        lm_stop
        ;;  
    lm_start)
        lm_start
        ;;  
    lm_restart)
        lm_stop
        lm_start
        ;; 
    *)
        echo "Usage: sh servers_process.sh or /etc/init.d/servers_process.sh
			> stop       # stop all services
			> start_r    # start record related services
			> start_w    # start watch related services
			> status     # check services status
			> real       # restart record udp2rtmp realrelayserver
			> wreal      # restart watch udp2rtmp realrelayserver
			> real_sec   # restart record udp2rtmp duhttp
			> wreal_sec  # restart watch udp2rtmp duhttp
			> gate       # restart record udp2rtmp gatewayserver
			> wgate      # restart watch udp2rtmp gatewayserver
			> check      # restart record udp2rtmp CheckServer
			> rgw        # restart record RGWServer
			> ech        # restart record EchoServer
			> wrgw       # restart record watchgw and watchr
			> rtu        # restart record GatewayRTU
			> watch      # restart watch related services
			> record     # restart record related services
			> core       # restart core-l2 related services
			> grab       # restart record udp2rtmp grabserver
			> channel_all           # restart all channel_proxy related services
			> channel_stop          # stop all channel_proxy related services
			> channel_start         # start all channel_proxy related services
			> channel_restart_8000  # restart 8000 channel_proxy services
			> channel_restart_9000  # restart 9000 channel_proxy services
			> channel_restart_8010  # restart 8010 channel_proxy services
			> channel_restart_9010  # restart 9010 channel_proxy services
			> lm_all                      # restart LM related services
			> lm_stop                     # stop LM related services
			> lm_start                    # start LM related services
			> lm_restart                  # restart LM related services
			"
        ;;
esac
