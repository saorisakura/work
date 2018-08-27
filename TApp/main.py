#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
"""
架构组件：
    CentOS MySQL SQLAlchemy Tornado

HTTP发包工具：
    Getman in WeChat
    Postman in Google Chrome

场景功能：
    用户注册
    图片上传加载
    加载H5页面

目录结构：
    common：存放公共类和方法
    conf: 存放配置文件
    log：存放相关日志
    static：存放静态文件，如样式（CSS）、脚本（js）、图片等
    templates：公用模板目录，主要存放 HTML 文件
    views：视图函数，业务逻辑代码目录
    main.py：Tornado 主程序入口
    models.py：数据库表结构定义...

约定服务器端 HTTP server 的端口号为 8000，服务器端和客户端定义的请求是 /users/regist，
那么完整的 URL 为 http://150.109.33.132:8000/users/regist?（请用自己的云虚拟机 IP 替换其中的 IP）。
参数为手机号（phone）、密码（password）及验证码（code），参数放入 HTTP 的 body 中，
具体为： {"phone":"18866668888","password":"demo123456","code":"123456"}

注：

确保服务器端 8000 端口已放通；
在实际的项目中，密码不会明文的传输，一般会在客户端先使用 md5 进行加密，服务器端存储的也是加密后的密码字符串。


调用逻辑：

                客户端注册请求   <<<---------
                        |                   |
                        |                   |
                        | post request      |
                        |                   |
      |---------->>>main.py                 |
      |                 |                   |
      |                 |url_router         |
      |                 |                   |
   models.py        users_url.py        JSON DATA / index.html
      |                 |                   |
      |db conf          |RegistHandle       |
      |                 |LoginHandle        |
      |                 |                   |
      |   ERROR_CODE    |                   |
   base.py<<<--->>>users_views.py >>>-------
                        |
                        |write
                        |
                     self.db

    客户端以 POST 的方式，发送注册请求至服务器端，
    请求进入服务器端的 main.py 后，
    将调用 url_router 转发到 users_url.py 中，
    在 users_urls.py 中，对应的 URL 将调用 users_views.py 的 RegistHandle 类， RegistHandle 为真正的代码处理逻辑，
    在校验用户信息正确的情况下，返回 JSON 格式的注册成功信息给客户端。...

"""

import tornado.ioloop
import tornado.web
import os
from tornado.options import define, options
from common.url_router import include, url_wrapper
from conf.base import BaseDB, engine
from models import initdb


class Application(tornado.web.Application):

    def __init__(self):
        initdb()
        handlers = url_wrapper([
            (r"/users/", include("views.users.users_urls")),
            (r"/upload/", include("views.upload.upload_urls"))
        ])
        settings = dict(
            debug=True,
            static_path=os.path.join(os.path.dirname(__file__), "static"),
            template_path=os.path.join(os.path.dirname(__file__), "template")
        )
        tornado.web.Application.__init__(self, handlers, **settings)


if __name__ == '__main__':
    print("Tornado server is ready for running.")
    tornado.options.parse_command_line()
    Application().listen(8000, xheaders=True)
    tornado.ioloop.IOLoop.instance().start()
