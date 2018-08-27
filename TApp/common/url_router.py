#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
from __future__ import unicode_literals
from importlib import import_module


def include(module):
    """
    根据传入得字符串，调用相应得模块，如module为字符串regist时，调用views.users.users_view.RegistHandle模块
    <module 'views.users.users_urls' from 'C:\\Users\\liyan\\PycharmProjects\\TApp\\views\\users\\users_urls.py'>
    [('regist', <class 'views.users.users_views.RegistHandler'>)]
    :param module:
    :return:
    """
    res = import_module(module)
    urls = getattr(res, "urls", res)  # the third arg is the default arg when there is not urls in module
    return urls


def url_wrapper(urls):
    """
    拼接请求url，调用相应模块，如拼接users和regist成url /users/regist,
    调用views.users.users_views.RegisHandle模块
    :param urls:
    :return:
    """
    wrapper_list = []
    for url in urls:
        path, handlers = url
        if isinstance(handlers, (tuple, list)):
            for handler in handlers:
                # 分离获取字符串（如regist）和调用类（如views.users.users_view.RegistHandle）
                pattern, handler_class = handler
                # 拼接url, 新的url的调用模块
                wrap = ("{0}{1}".format(path, pattern), handler_class)
                wrapper_list.append(wrap)
        else:
            wrapper_list.append((path, handlers))

    return wrapper_list
