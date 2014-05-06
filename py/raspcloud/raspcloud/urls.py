# -*- coding: utf-8 -*-
from django.conf.urls import patterns, include, url

from django.contrib import admin
from raspcloud.views import hello
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r'^$', hello),
    url(r'^img/(?P<path>.*)$','django.views.static.serve',
        {'document_root':'E:/django/mysite/static/img/'}),
    url(r'^css/(?P<path>.*)$','django.views.static.serve',
        {'document_root':'E:/django/mysite/static/css/'}),
    url(r'^js/(?P<path>.*)$','django.views.static.serve',
        {'document_root':'E:/django/mysite/static/js/'}),
)
