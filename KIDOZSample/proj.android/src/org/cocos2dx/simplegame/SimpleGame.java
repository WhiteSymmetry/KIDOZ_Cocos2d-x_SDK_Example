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

import android.graphics.Color;
import android.os.Bundle;
import android.view.ViewGroup.LayoutParams;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.kidoz.sdk.api.FeedButton;
import com.kidoz.sdk.api.FlexiView;
import com.kidoz.sdk.api.KidozBanner;
import com.kidoz.sdk.api.KidozSDK;
import com.kidoz.sdk.api.PanelView;
import com.kidoz.sdk.api.interfaces.FlexiViewListener;
import com.kidoz.sdk.api.ui_views.flexi_view.FLEXI_POSITION;
import com.kidoz.sdk.api.ui_views.kidoz_banner.KidozBannerListener;

public class SimpleGame extends Cocos2dxActivity {
	private FeedButton mFeedButton;
	private PanelView mPanelView;
	private KidozBanner mKidozBanner;
	private FlexiView mFlexiView;
	
	private RelativeLayout mSdkContainer;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		// Initialize SDK instance
		KidozSDK.initialize(SimpleGame.this, "5","i0tnrdwdtq0dm36cqcpg6uyuwupkj76s");

		// Create a container that will hold KIDOZ elements
		mSdkContainer = new RelativeLayout(getContext());

		// Add container to main application view
		addContentView(mSdkContainer, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));

		/** Initiate and add Feed Button view */
		addFeedButtonToView();

		/** Initiate and add Panel view */
		addPanelToView();

		/** Initiate and add Banner view */
		addBannerToView();
		
		/** Initiate and add Flexi view */
		addFlexiPointToView();
	}

	
	/** Initiate and add Feed Button view */
	private void addFeedButtonToView() {
		// Create KIDOZ Feed Button instance
		mFeedButton = new FeedButton(this);

		// Add button to container and place it as desired
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
		params.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
		mSdkContainer.addView(mFeedButton, params);
	}

	/** Initiate and add Panel view */
	private void addPanelToView() {
		// Create KIDOZ Panel View instance
		mPanelView = new PanelView(this);
		mPanelView.setPanelColor(Color.CYAN); // Default color is White

		// Add panel to container and place it as desired
		mSdkContainer.addView(mPanelView, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
	}

	/** Initiate and add Banner view */
	private void addBannerToView() {
		// Create KIDOZ Banner View View instance
		mKidozBanner = new KidozBanner(this);
		mKidozBanner.setKidozBannerListener(new KidozBannerListener() {
			@Override
			public void onBannerReady() {
				super.onBannerReady();
				mKidozBanner.showBanner();
			}
		});

		// Add banner to container and place it as desired
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
		params.addRule(RelativeLayout.ALIGN_LEFT);
		mSdkContainer.addView(mKidozBanner, params);
	}
	
	private void addFlexiPointToView() {
		mFlexiView = (new FlexiView(SimpleGame.this));
		mFlexiView.setAutoShow(true);
		mFlexiView.setFlexiViewInitialPosition(FLEXI_POSITION.MIDDLE_CENTER);
		mFlexiView.setOnFlexiViewEventListener(new FlexiViewListener() {
			@Override
			public void onViewReady() {
				super.onViewReady();
				Toast.makeText(SimpleGame.this, "Flexi Ready",
						Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onViewHidden() {
				super.onViewHidden();
				Toast.makeText(SimpleGame.this, "Flexi Hidden",
						Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onViewVisible() {
				super.onViewVisible();
				Toast.makeText(SimpleGame.this, "Flexi Visible",
						Toast.LENGTH_SHORT).show();
			}
		});
		
		// Add flexi view to container  
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
		params.addRule(RelativeLayout.ALIGN_LEFT);
		mSdkContainer.addView(mFlexiView, params);
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
