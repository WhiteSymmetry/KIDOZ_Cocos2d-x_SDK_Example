/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package org.cocos2dx.simplegame;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.kidoz.sdk.api.FeedButton;
import com.kidoz.sdk.api.KidozSDK;
import com.kidoz.sdk.api.PanelView;

import android.graphics.Color;
import android.os.Bundle;
import android.view.ViewGroup.LayoutParams;
import android.widget.RelativeLayout;

public class SimpleGame extends Cocos2dxActivity {
	private FeedButton mFeedButton;
	private PanelView mPanelView;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		// Initialize sdk instance
		KidozSDK.initialize(SimpleGame.this, "5",
				"i0tnrdwdtq0dm36cqcpg6uyuwupkj76s");

		// Create a container that will hold kidoz elements
		RelativeLayout mSdkContainer = new RelativeLayout(getContext());

		// Create Kidoz Feed Button instance
		mFeedButton = new FeedButton(this);

		// Add button to container and place it as desired
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
		params.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
		mSdkContainer.addView(mFeedButton, params);

		// Create Kidoz Panel View instance
		mPanelView = new PanelView(this);
		mPanelView.setPanelColor(Color.CYAN); // Default color is White
		
		// Add panel to container and place it as desired
		mSdkContainer.addView(mPanelView, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));

		// Add container to main application view
		addContentView(mSdkContainer, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
	}

	@Override
	protected void onStop() {
		super.onStop();

		android.os.Process.killProcess(android.os.Process.myPid());
		System.exit(1);
	}

	static {
		System.loadLibrary("game");
	}

	@Override
	public void onBackPressed() {
		android.os.Process.killProcess(android.os.Process.myPid());
		System.exit(1);
	}
}
