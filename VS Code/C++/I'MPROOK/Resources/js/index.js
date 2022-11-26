$(document).ready(function() {
    $("#top").hide()
    $(window).scroll(function() {
        if ($(this).scrollTop() >= 550)
            $("#top").show("slow")
        else {
            $("#top").hide("slow")
        }
    })

    $("#top").click(function() {
        $("html, body").animate({
            scrollTop: 0
        }, 1000)
    })
})

// $(window).on(".Load", function(event) {
//     $("body").removeClass("Preloading");
//     $(".Load").delay(1000).fadeOut("fast");

// });

$(document).ready(function() {
    $(".Bar__Inner  a").click(function() {
        event.preventDefault()
    })

    //Cái này sau gắn link vào là xóa đi
    // $("div#Tab3-1 a").click(function() {
    //     event.preventDefault()
    // })

    //=======================================

    $("div#Tab4-2 a").click(function() {
        event.preventDefault()
    })

    $("ul.Tab a").click(function() {
        event.preventDefault()
    })

    $("ul.Tab1-1 a").click(function() {
        event.preventDefault()
    })

    $("div.Flex-Wrapper a").click(function() {
        event.preventDefault()
    })

    $("div.Tech-Demonstration-Second a").click(function() {
        event.preventDefault()
    })

    $("ul.ListNews a").click(function() {
        event.preventDefault()
    })

    $("div.Footer__Inner a").click(function() {
        event.preventDefault()
    })

})



$(document).ready(function() {
    /*Ẩn hết ảnh điện thoại trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Phone").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item1:first-child > a").addClass("Bottom-Shadow")


    $("li.Item1 > a").hover(function() {

        $("li.Item1 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Phone").hide()
        $(user_hover).show()

        $("li.Item1 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh Màn Hình trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-TV").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item2:first-child > a").addClass("Bottom-Shadow")

    $("li.Item2 > a").hover(function() {
        $("li.Item2 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-TV").hide()
        $(user_hover).show()


        $("li.Item2 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh Laptop trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Laptop").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item3:first-child > a").addClass("Bottom-Shadow")

    $("li.Item3 > a").hover(function() {
        $("li.Item3 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Laptop").hide()
        $(user_hover).show()


        $("li.Item3 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh Laptop trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Discover").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item4:first-child > a").addClass("Bottom-Shadow")

    $("li.Item4 > a").hover(function() {
        $("li.Item4 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Discover").hide()
        $(user_hover).show()


        $("li.Item4 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh Laptop trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Endow").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item5:first-child > a").addClass("Bottom-Shadow")

    $("li.Item5 > a").hover(function() {
        $("li.Item5 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Endow").hide()
        $(user_hover).show()


        $("li.Item5 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Support").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item6:first-child > a").addClass("Bottom-Shadow")

    $("li.Item6 > a").hover(function() {
        $("li.Item6 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Support").hide()
        $(user_hover).show()


        $("li.Item6 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    /*Ẩn hết ảnh trừ cái đầu tiên*/
    $("ul.Menu>li:not(:first-child)>div.IMG-Enterprise").hide()
        /*add class gạch chân vào link đầu tiên*/
    $("li.Item7:first-child > a").addClass("Bottom-Shadow")

    $("li.Item7 > a").hover(function() {
        $("li.Item7 > a").removeClass("Show-IMG")
        $(this).addClass("Show-IMG")

        var user_hover = $(this).attr("href")
        $("ul.Menu>li>div.IMG-Enterprise").hide()
        $(user_hover).show()


        $("li.Item7 > a").removeClass("Bottom-Shadow")
    })
})

$(document).ready(function() {
    $("div.Tab-Content > div:not(:first-child)").hide()

    $("ul.Tab a").click(function() {
        $("ul.Tab a").removeClass("Click-Active")
        $(this).addClass("Click-Active")

        var user_click = $(this).attr("href")
        $("div.Tab-Content > div").hide()
        $(user_click).show()

        $("ul.Tab li").removeClass("Click-Active")
    })
})

$(document).ready(function() {
    $("div.Tab-Content1 > div:not(:first-child)").hide()

    $("ul.Tab1-1 a").click(function() {
        $("ul.Tab1-1 a").removeClass("Click-Active1")
        $(this).addClass("Click-Active1")

        var user_click = $(this).attr("href")
        $("div.Tab-Content1 > div").hide()

        $(user_click).show()
        $("ul.Tab1-1 li").removeClass("Click-Active1")

    })
})

// $(document).ready(function() {
//     $("li.Sub > a").hover(function() {
//         $("li.Sub > a").removeClass("Hover-li-In-Bar")
//         $(this).addClass("Hover-li-In-Bar")
//     })
// })

// $(document).ready(function() {
//     $("ul.MenuActive__ListItems").hover(function() {
//         $("li.Sub>a").removeClass("Hover-li-In-Bar")
//         $(li.Sub > a).addClass("Hover-li-In-Bar")
//     })
// })