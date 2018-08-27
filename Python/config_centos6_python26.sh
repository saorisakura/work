#!/bin/bash

#wget -O /etc/yum.repos.d/saltstack-salt-5.repo http://oper.6rooms.com/setup/saltstack-salt-5.repo
yum -y --disablerepo=epel install libffi-devel python-distribute  python-devel python-pip

#yum install python-msgpack python-requests python-six python-babel python-backports-ssl_match_hostname python-chardet libyaml
yum -y install python-requests python-six python-babel python-backports-ssl_match_hostname python-chardet libyaml
#wget -O /root/softwares/salt_rtmp6.tar.gz http://oper.6rooms.com/setup/salt_rtmp6.tar.gz
#cd /root/softwares
#tar zxf salt_rtmp6.tar.gz
#cd salt_rtmp6
#rpm -ivh *.rpm

cd /root/softwares
wget -O /root/softwares/rtmpdump-2.3.tgz http://oper.6rooms.com/others/rtmpdump-2.3.tgz
tar zxf rtmpdump-2.3.tgz
cd rtmpdump-2.3
make SYS=posix
make install


sed -i '/^\/usr\/local\/lib$/d' /etc/ld.so.conf
echo '/usr/local/lib' >> /etc/ld.so.conf
ldconfig
ldconfig


#pip install python-librtmp
cd /root/softwares
wget -O /root/softwares/cffi-1.11.2.tar.gz http://oper.6rooms.com/others/python/cffi-1.11.2.tar.gz
wget -O /root/softwares/pycparser-2.18.tar.gz http://oper.6rooms.com/others/python/pycparser-2.18.tar.gz
wget -O /root/softwares/python-librtmp-0.3.0.tar.gz http://oper.6rooms.com/others/python/python-librtmp-0.3.0.tar.gz
wget -O /root/softwares/singledispatch-3.4.0.3-py2.py3-none-any.whl http://oper.6rooms.com/others/python/singledispatch-3.4.0.3-py2.py3-none-any.whl
wget -O /root/softwares/setuptools-32.3.1-py2.py3-none-any.whl http://oper.6rooms.com/others/python/setuptools-32.3.1-py2.py3-none-any.whl
wget -O /root/softwares/pip-9.0.1-py2.py3-none-any.whl http://oper.6rooms.com/others/python/pip-9.0.1-py2.py3-none-any.whl
pip install /root/softwares/setuptools-32.3.1-py2.py3-none-any.whl
pip install /root/softwares/pip-9.0.1-py2.py3-none-any.whl
pip install /root/softwares/singledispatch-3.4.0.3-py2.py3-none-any.whl

tar zxf pycparser-2.18.tar.gz
cd pycparser-2.18
python setup.py install
cd ..

tar zxf cffi-1.11.2.tar.gz
cd cffi-1.11.2
python setup.py install
cd ..

tar zxf python-librtmp-0.3.0.tar.gz
cd python-librtmp-0.3.0
python setup.py install
cd ..

