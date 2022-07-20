from asyncio.windows_events import NULL
from django.http import HttpResponse
from django.shortcuts import redirect, render
from .models import Task
from django.utils import timezone

# Create your views here.
def task_list(request):
    # add and update tasks
    if request.method=="POST":
        if request.POST.get('task_id',False) != NULL:
            # for update
            Task.objects.filter(task_id=request.POST['task_id']).update(task_title=request.POST['task_title'],task_description=request.POST['task_description'],task_updated_datetime=timezone.now())
            return redirect(viewAll)
        else:
            # for add
            post=Task()
            post.task_title=request.POST['task_title']
            post.task_description=request.POST['task_description']
            post.save()
            return redirect(viewAll)
    else:
        tasks = Task.objects.all()
        return render(request, 'todotasks/task_list.html', {'tasks':tasks})

def viewAll(request):
    tasks = Task.objects.all()
    return render(request, 'todotasks/task_list.html', {'tasks':tasks})


def is_task_done(request,id):
    task=Task.objects.filter(task_id=id)
    task.update(task_is_done=True)
    return redirect(viewAll)

def is_task_undone(request,id):
    task=Task.objects.filter(task_id=id)
    task.update(task_is_done=False)
    return redirect(viewAll)

# fetch row for the task to be updated using task_id
def fetchRow(request,id):
    task_row=Task.objects.filter(task_id=id)
    return render(request, 'todotasks/task_list.html', {'task_row':task_row})

def delete_task(request,id):
    task=Task.objects.filter(task_id=id).delete()
    return redirect(viewAll)


