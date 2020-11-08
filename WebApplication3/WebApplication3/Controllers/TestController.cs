using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Text;
using System.IO;

namespace WebApplication3.Controllers
{
    public class TestController : Controller
    {
        // GET: Test
        public ActionResult Index()
        {
            return View();
        }

  
        public ActionResult index2(string username,string psd,string email,string code,
            string sex,string birthday,string old,string province,string city,string grxl,
            string score,string[] like,string myfile,string intro)
        {
            ViewBag.telephone = username;
            ViewBag.pad = psd;
            ViewBag.email = email;
            ViewBag.yzm= code;
            ViewBag.sex = sex;
            ViewBag.birthday = birthday;
            ViewBag.age = old;
            ViewBag.province = province;
            ViewBag.city = city;
            ViewBag.grxl = grxl;
            ViewBag.score = score;
            ViewBag.myfile = myfile;
            StringBuilder resultStr = new StringBuilder();
            for(int i=0; i<like.Length;i++)
            {
                resultStr.Append(like[i] + " ");
            }
            ViewBag.like = resultStr.ToString();
            ViewBag.intro = intro;
            return View();
        }
    }
}