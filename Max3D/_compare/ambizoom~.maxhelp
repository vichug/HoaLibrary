{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 311.0, 66.0, 601.0, 490.0 ],
		"bglocked" : 0,
		"defrect" : [ 311.0, 66.0, 601.0, 490.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 10.0, 10.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Based on the b_zoom VST plugin by Dave Malham. Ported to MAX/MSP by Matthew Paradis\n\nMRC University of York\n\nAll parameters are scaled between 0.0-1.0\n\nazimuth = azimuth, \nelevation = elevation,\nzoom = zoom.\n\nFor more informataion see: http://www.york.ac.uk/inst/mustech/3d_audio/vst/bzoom_help.html",
					"linecount" : 14,
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 260.0, 80.0, 310.0, 200.0 ],
					"id" : "obj-16",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "w         x        y        z  ",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 80.0, 190.0, 128.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "w         x        y        z  ",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 80.0, 130.0, 128.0, 20.0 ],
					"id" : "obj-9",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"varname" : "autohelp_top_title",
					"text" : "ambizoom~",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontface" : 3,
					"fontsize" : 20.871338,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"patching_rect" : [ 15.0, 13.0, 566.0, 30.0 ],
					"id" : "obj-110",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"varname" : "autohelp_top_digest",
					"text" : "Ambisonic B-format zoom control",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.754705,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"patching_rect" : [ 15.0, 45.0, 566.0, 21.0 ],
					"id" : "obj-111",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "ambizoom~",
					"numinlets" : 4,
					"numoutlets" : 4,
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "signal", "signal", "signal" ],
					"patching_rect" : [ 80.0, 160.0, 123.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"varname" : "autohelp_top_panel",
					"numinlets" : 1,
					"background" : 1,
					"numoutlets" : 0,
					"grad1" : [ 0.117647, 0.203922, 0.435294, 1.0 ],
					"grad2" : [ 0.352941, 0.439216, 0.713726, 1.0 ],
					"patching_rect" : [ 10.0, 10.0, 570.0, 60.0 ],
					"mode" : 1,
					"id" : "obj-114",
					"bgcolor" : [ 0.756863, 0.564706, 0.105882, 1.0 ]
				}

			}
 ],
		"lines" : [  ]
	}

}
